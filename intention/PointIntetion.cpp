#include "intention.h"
#include <algorithm>

class PointIntetion : Intetion {
    Vector2 target;

    PointIntetion(QString name, float weight, Vector2 target, float radius) : Intetion(name, weight){
        this->name = name;
        this->weight = weight;

        this->target = target;

        this->radius = radius;
    }

    Qlist<float> compute(Vector2 position, float orientation) {
        Vector2 to_target = Vector2.sub(position, this->target);
        float to_target_scalar = to_target.Length();

        Vector2 to_target_norm = to_target.Normalize();

        float to_target_scalar_norm = max(0, min(1, to_target_scalar/this->radius));

        float force = to_target_scalar_norm * 1; // may be the force as a func.

        QList<float> response = {to_target_norm.X, to_target_norm.Y, 0};

        return response;
    }
};
