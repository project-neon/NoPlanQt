#ifndef NOPLAN_DETECTION_H
#define NOPLAN_DETECTION_H
#include <list>
#include "robocup_ssl_client.h"

class noplan_detection
{
public:
    noplan_detection();
    std::vector<SSL_DetectionRobot> blue_robots;
    std::vector<SSL_DetectionRobot> yellow_robots;
    SSL_DetectionBall ball;
    double t_capture;
    int frame_number;
    std::vector<SSL_DetectionRobot> get_our_robots();
    std::vector<SSL_DetectionRobot> get_foe_robots();
};

#endif // NOPLAN_DETECTION_H
