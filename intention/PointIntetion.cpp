#include "intention.h"

class PointIntetion : Intetion {
    Vector2 target;

    PointIntetion(QString name, float weight, Vector2 target) : Intetion(name, weight){
        this->name = name;
        this->weight = weight;

        this->target = target;
    }

    RobotTask compute(Vector2 position, float orientation) {
        Vector2 to_target = position - target;

        float to_target_scalar = to_target.Length();
    }
};
