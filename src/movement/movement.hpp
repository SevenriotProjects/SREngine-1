#ifndef INPUT_HPP
#define INPUT_HPP

#include "../worldmap/world.hpp"
#include <SDL2/SDL.h>
#include <unordered_map>

class InputManager {
public:
    void handleEvent(const SDL_Event &event);
    void update(Camera &camera);

private:
    std::unordered_map<SDL_Scancode, bool> keys;
};

#endif

/*
#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <SDL2/SDL.h>
#include <unordered_map>

class InputManager {
public:
    void handleEvent(const SDL_Event &event);
    void update(Camera &camera);

private:
    std::unordered_map<int, bool> keys;

    float velocity = 0.0f;
    float maxSpeed = 5.0f;
    float acceleration = 0.2f;
    float friction = 0.1f;

    bool isJumping = false;
    float jumpVelocity = 0.0f;
    float gravity = 0.05f;
    float maxJumpHeight = 1.5f;

    void MV_JumpMove(Camera &camera);
    void MV_WalkMove(Camera &camera, float forward, float strafe);
    void MV_SlideMove(Camera &camera);
    void MV_Backwards(Camera &camera, float backwardSpeed);

};

#endif // MOVEMENT_HPP
*/