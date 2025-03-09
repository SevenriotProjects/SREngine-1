#include "renderer.hpp"
#include "../math/math.hpp"
#include <SDL2/SDL.h>

Renderer::Renderer(SDL_Renderer *renderer) : renderer(renderer) {}

void Renderer::render(const World &world) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    const auto &camera = world.camera;
    for (const auto &object : world.objects) {
        for (const auto &line : object.lines) {
            // Transform points to camera space
            Vector3 start = camera.transformPoint(line.start);
            Vector3 end = camera.transformPoint(line.end);

            // Perform perspective projection
            int x1, y1, x2, y2;
            if (project(start, x1, y1) && project(end, x2, y2)) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

bool Renderer::project(const Vector3 &point, int &x, int &y) {
    if (point.z <= 0) return false; // Ignore points behind the camera

    // Simple perspective projection
    float scale = 500.0f / point.z;
    x = static_cast<int>(640 + point.x * scale);
    y = static_cast<int>(360 - point.y * scale);
    return true;
}
