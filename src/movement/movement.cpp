/*#include "movement.hpp"
#include "../math/math.cpp"
#include <cmath>
#include <iostream>

void InputManager::handleEvent(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        keys[event.key.keysym.scancode] = true;
    } else if (event.type == SDL_KEYUP) {
        keys[event.key.keysym.scancode] = false;
    }
}

void InputManager::update(Camera &camera) {
    float forward = 0.0f;
    float strafe = 0.0f;

    if (keys[SDL_SCANCODE_W]) forward += 1.0f;
    if (keys[SDL_SCANCODE_S]) forward -= 1.0f;
    if (keys[SDL_SCANCODE_A]) strafe -= 1.0f;
    if (keys[SDL_SCANCODE_D]) strafe += 1.0f;

    MV_WalkMove(camera, forward, strafe);

    if (keys[SDL_SCANCODE_SPACE]) MV_JumpMove(camera);
    if (keys[SDL_SCANCODE_LSHIFT]) MV_SlideMove(camera);
    if (keys[SDL_SCANCODE_S]) MV_Backwards(camera, 0.5f);
}

// Handles jumping logic
void InputManager::MV_JumpMove(Camera &camera) {
    if (!isJumping) {
        isJumping = true;
        jumpVelocity = 0.3f; // Initial jump velocity
    }

    if (isJumping) {
        camera.position.y += jumpVelocity;
        jumpVelocity -= gravity;

        if (camera.position.y <= 0.0f) { // Ground check
            camera.position.y = 0.0f;
            isJumping = false;
            jumpVelocity = 0.0f;
        }
    }
}

// Handles normal walking
void InputManager::MV_WalkMove(Camera &camera, float forward, float strafe) {
    // Normalize movement vector
    float magnitude = MT_Rsqrt(forward * forward + strafe * strafe);
    if (magnitude > 0.0f) {
        forward *= magnitude;
        strafe *= magnitude;
    }

    // Apply acceleration and velocity
    velocity = std::fmin(velocity + acceleration, maxSpeed);
    camera.position.x += strafe * velocity;
    camera.position.z += forward * velocity;

    // Apply friction
    velocity = std::fmax(velocity - friction, 0.0f);
}

// Handles sliding
void InputManager::MV_SlideMove(Camera &camera) {
    velocity = std::fmin(velocity + acceleration * 1.5f, maxSpeed * 1.5f); // Faster slide
    camera.position.x += velocity * 0.1f; // Sliding in current direction
}

// Handles backward movement with reduced speed
void InputManager::MV_Backwards(Camera &camera, float backwardSpeed) {
    camera.position.z -= backwardSpeed;
}

*/

#include "movement.hpp"
#include <SDL2/SDL.h>

void InputManager::handleEvent(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        keys[event.key.keysym.scancode] = true;
    } else if (event.type == SDL_KEYUP) {
        keys[event.key.keysym.scancode] = false;
    }
}

void InputManager::update(Camera &camera) {
    if (keys[SDL_SCANCODE_W]) camera.position.z += 0.1f;
    if (keys[SDL_SCANCODE_S]) camera.position.z -= 0.1f;
    if (keys[SDL_SCANCODE_A]) camera.position.x -= 0.1f;
    if (keys[SDL_SCANCODE_D]) camera.position.x += 0.1f;
    if (keys[SDL_SCANCODE_Q]) camera.position.y += 0.1f;
    if (keys[SDL_SCANCODE_E]) camera.position.y -= 0.1f;
}
