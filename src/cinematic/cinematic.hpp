#ifndef CINEMATIC_HPP
#define CINEMATIC_HPP
#include <SDL2/SDL.h>

void cine_pic(SDL_Renderer* renderer, const std::string& imagePath, int displayTimeMs);

#endif