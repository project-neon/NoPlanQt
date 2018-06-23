#include "math/vector2.h"

Vector2::Vector2(void) {}

Vector2::Vector2(float X, float Y) {

    this->X = X;
    this->Y = Y;

}

float Vector2::Length() {

    return sqrt(X * X + Y * Y);

}

// Normalizes the vector
Vector2 Vector2::Normalize() {

    Vector2 vector;
    float length = this->Length();

    if(length != 0) {
        vector.X = X/length;
        vector.Y = Y/length;
    }

    return vector;

}

Vector2::~Vector2(void) {}

static Vector2 sum(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.X + v2.X, v1.Y + v2.Y);
}
static Vector2 sub(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.X - v2.X, v1.Y - v2.Y);
}
static Vector2 mult(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.X * v2.X, v1.Y * v2.Y);
}

static Vector2 mult(Vector2 v1, float f) {
    return Vector2 (v1.X * f, v1.Y * f);
}

static Vector2 div(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.X / v2.X, v1.Y / v2.Y);
}
//Theta has to be in radians
static Vector2 fromTheta(float theta) {
    return Vector2 (cos(theta), sin(theta));
}
static float angle(Vector2 v1) {
    return atan2(v1.X, v1.Y);
}

static Vector2 rotate(Vector2 v1, float theta) {
    float current_theta = atan2(v1.X, v1.Y);
    float current_norm  = v1.Length();

    Vector2 vect = fromTheta(current_theta + theta);

    return mult(vect, current_norm);
}
