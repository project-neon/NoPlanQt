#ifndef INTENTION_H
#define INTENTION_H

#include "coach/coach.h"

#include <QString>

#include <math/vector2.h>


class Intetion{
public:
    QString name;
    float weight;

    Intetion(QString name, float weight);

    RobotTask compute(Vector2 position, float orientation);
};

#endif
