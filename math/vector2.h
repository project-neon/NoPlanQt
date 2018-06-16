#pragma once

#include <math.h>

class Vector2 {
public:

    float X,Y;

    Vector2(void);
    Vector2(float X, float Y);
    ~Vector2(void);

    float Length();
    Vector2 Normalize();

    static Vector2 sum(Vector2 v1, Vector2 v2);
    static Vector2 sub(Vector2 v1, Vector2 v2);
    static Vector2 mult(Vector2 v1, Vector2 v2);
    static Vector2 div(Vector2 v1, Vector2 v2);
    static Vector2 fromTheta(float theta);
    static float angle(Vector2 v1, Vector2 v2);
    static float angleBetween(Vector2 v1, Vector2 v2);
    static float angleBetween(Vector2 v1, float theta);

};
