#ifndef WORLD_HPP
#define WORLD_HPP

#include "../math/math.hpp"
#include <vector>

struct Line {
    Vector3 start, end;
};

struct Object {
    std::vector<Line> lines;
};

class Camera {
public:
    Camera();

    Vector3 transformPoint(const Vector3 &point) const;

    Vector3 position;
};

class World {
public:
    World();

    std::vector<Object> objects;
    Camera camera;
};

#endif
