#pragma once

#include <list>

#include "robocup_ssl_client.h"

class noplan_detection {

public:

    double t_capture;
    int frame_number;

    noplan_detection();
    SSL_DetectionBall ball;

    std::vector<SSL_DetectionRobot> blue_robots;
    std::vector<SSL_DetectionRobot> yellow_robots;
    std::vector<SSL_DetectionRobot> get_our_robots();
    std::vector<SSL_DetectionRobot> get_foe_robots();

};
