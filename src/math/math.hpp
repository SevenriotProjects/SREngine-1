#ifndef MATH_HPP
#define MATH_HPP

int MT_Add(int count, ...);
int MT_Substract(int count, ...);
float MT_rsqrt( float number );

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 operator-(const Vector3 &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }
};

#endif