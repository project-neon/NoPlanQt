#pragma once

#include <math.h>
#include <QtMath>

class Vector2 {
public:

    float X,Y;

    Vector2(void);
    Vector2(float X, float Y);
    ~Vector2(void);

    float Length();
    Vector2 Normalize();

    static float sum(Vector2 v1, Vector2 v2);
    static float sub(Vector2 v1, Vector2 v2);
    static float mult(Vector2 v1, Vector2 v2);
    static float div(Vector2 v1, Vector2 v2);
    static float fromTheta(float theta);
    static float angle(Vector2 v1, Vector2 v2);
    static float angleBetween(Vector2 v1, Vector2 v2);
    static float angleBetween(Vector2 v1, float theta);

};
