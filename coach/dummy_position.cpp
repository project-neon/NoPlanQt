#include "coach.h"

#include <intention/PointIntetion.cpp>

class DummyPosition: public Position {


    PointIntetion to_center_field;

    DummyPosition(){
        PointIntetion to_center_field = PointIntetion("to_center_field", 1.f, Vector2(0.f, 0.f), 1000);
    }

    RobotTask calculate(SSL_DetectionRobot *robot, QHash<int, SSL_DetectionRobot> *our_robots,
                        QList<SSL_DetectionRobot> *their_robots, SSL_DetectionBall *ball){


        return RobotTask(robot->robot_id(), true, 0.f, 0.f);
    }
};
