#ifndef INTENTION_H
#define INTENTION_H

#include "coach/coach.h"

#include <QString>
#include <boost/array.hpp>


class Intetion{
public:
    QString name;
    float weight;

    Intetion(QString name, float weight);

    RobotTask compute(boost::array<int, 2> position, float orientation);

};

#endif
