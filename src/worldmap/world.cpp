#include "world.hpp"
#include <cmath>

Camera::Camera() : position({0.0f, 0.0f, -5.0f}) {}

Vector3 Camera::transformPoint(const Vector3 &point) const {
    // Translate based on camera position
    return point - position;
}

World::World() {
    // Add a simple cube
    Object cube = {
        {
            {{-1, -1, -1}, {1, -1, -1}},
            {{1, -1, -1}, {1, 1, -1}},
            {{1, 1, -1}, {-1, 1, -1}},
            {{-1, 1, -1}, {-1, -1, -1}},

            {{-1, -1, 1}, {1, -1, 1}},
            {{1, -1, 1}, {1, 1, 1}},
            {{1, 1, 1}, {-1, 1, 1}},
            {{-1, 1, 1}, {-1, -1, 1}},

            {{-1, -1, -1}, {-1, -1, 1}},
            {{1, -1, -1}, {1, -1, 1}},
            {{1, 1, -1}, {1, 1, 1}},
            {{-1, 1, -1}, {-1, 1, 1}},
        }};
    objects.push_back(cube);
}
