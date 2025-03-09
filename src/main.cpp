// core
#include <stdio.h>
#include <cstring>
#include <windows.h>
#include <thread>
#include <iostream>
#define SDL_MAIN_HANDLED


// Engine core files
#include "cvar/cvar.hpp"
#include "chat/chat.hpp"
#include "console\console.hpp"
#include "common\com.hpp"
#include "cmd/cmd.hpp"
#include "entities/entities.hpp"
#include "server/sv_main.hpp"
#include "server/sv_commands.hpp"
#include "color/codes.hpp"

#include "renderer/renderer.hpp"
#include "worldmap/world.hpp"
#include "movement/movement.hpp"

// todo
//#include "weapons/weapons.hpp"
//#include "bsp/bsp.h"
//#include "sounds/sounds.h"
//#include "network/network.h"
//#include "textures/texture_loader.hpp"

// Client render core
#include "client/cl.hpp"
#include "renderer/renderer.hpp"
#include "cinematic/cinematic.hpp"
//#include "renderer/fps.hpp"

bool running = true;

void createConsole()
{
    AllocConsole(); // Create a new console window
//    FILE* fp;
    freopen("CONOUT$", "w", stdout); // Redirect stdout
    freopen("CONIN$", "r", stdin);  // Redirect stdin
    freopen("CONOUT$", "w", stderr); // Redirect stderr
    std::cout << "Console initialized. Type commands below:\n";
}

/*void consoleLoop()
{
    bool running = true;
    while (running) {
        char input[64];

        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break; // Read input as a string
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
            running = false; // Exit loop on 'q' or 'Q'
        } else {
            Cmd_ExecuteCommand(input);
        }
    }
}*/

DWORD WINAPI consoleInputThread(LPVOID lpParam) {
    while (running) {
        char input[64];
        printf("> ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
                running = false;
            } else {
                Cmd_ExecuteCommand(input);
            }
        }
    }
    return 0;
}


//int main(int argc, char *argv[])
int console_loggers()
{
    SetConsoleTitle("SVEN test show");

    printf("=== Sven Engine ===\n");
    printf("Risen Arena 1.0 x64 build");

    // Set and get Cvars
    printf("\n-- Cvar System --\n");
    Cvar_Set("jump_height", "1.5");
    Cvar_Set("player_speed", "5.0");
    printf("Jump height: %s\n", Cvar_Get("jump_height"));
    printf("Player speed: %s\n", Cvar_Get("player_speed"));

    // Chat system
    printf("\n-- Chat System --\n");
    chat_send("Player1", "Hello!");
    chat_send("Player2", "Hi there!");
    chat_print_all();

    // Entities
    printf("\n-- Entities System --\n");
    entity_create("Player1", 10.0f, 20.0f);
    entity_create("Enemy1", 15.0f, 25.0f);
    entity_print_all();

    SV_AddOperatorCommand();
    CL_AddCommands();




//    printf("\n=== Sven Engine Shutdown ===\n");

    return 0;
}


int main(int argc, char *argv[])
{

    HANDLE hThread = CreateThread(NULL, 0, consoleInputThread, NULL, 0, NULL);
    if (hThread == NULL) {
        fprintf(stderr, "Failed to create thread.\n");
        return 1;
    }

    if(Cvar_FindVar("sven_dev") != NULL)
    {
        SetConsoleColor(2);
    }

    Com_DCprintf(("^1SVEN Engine: DEVELOPER MODE IS ON!\n"));

    Com_DCprintf("^2 INITIALIZED CONSOLE \n");
    // Main render loop here...


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL Initialization failed: %s\n", SDL_GetError());
        return 1;
    } else {
        Com_Dprintf("SVEN ENGINE: INITIALIZED SDL.\n");
    }

    SDL_Window *window = SDL_CreateWindow(
        "SVEN ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_SHOWN);

    if (!window) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Renderer myRenderer(renderer);
    World world;
    InputManager inputManager;

//    bool running = true;
    SDL_Event event;

    createConsole();
    console_loggers();
    cine_pic( renderer, "intro.png", 3000 );

    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            inputManager.handleEvent(event);
        }

        inputManager.update(world.camera);
        myRenderer.render(world);

        SDL_Delay(12); // ~60 FPS

    }



    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}