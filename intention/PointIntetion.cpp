#include "intention.h"

class PointIntetion : Intetion {
    PointIntetion(QString name, float weight, boost::array<int, _Tp2> target) : Intetion(name, weight){
        this->name = name;
        this->weight = weight;
    }

    RobotTask compute(boost::array<int, _Tp2> position, float orientation) {

    }
};
