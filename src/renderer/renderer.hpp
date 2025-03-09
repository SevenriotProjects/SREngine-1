#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../worldmap/world.hpp"
#include <SDL2/SDL.h>

class Renderer {
public:
    explicit Renderer(SDL_Renderer *renderer);

    void render(const World &world);

private:
    SDL_Renderer *renderer;

    bool project(const Vector3 &point, int &x, int &y);
};

#endif
