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

static float sum(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.x + v2.x, v1.y + v2.y);
}
static float sub(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.x - v2.x, v1.y - v2.y);
}
static float mult(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.x * v2.x, v1.y * v2.y);
}
static float div(Vector2 v1, Vector2 v2) {
    return Vector2 (v1.x / v2.x, v1.y / v2.y);
}
//Theta has to be in radians
static float fromTheta(float theta) {
    return Vector2 (qCos(theta), qSin(theta));
}
static float angle(Vector2 v1) {
    return qAtan2(v1.x, v1.y);
}
