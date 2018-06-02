#ifndef COACH_H
#define COACH_H
#include "player.h"
#include "detection/noplan_detection.h"
#include <vector>
#include <QHash>
#include "commons.h"

class RobotTask
{
public:
    int robot_id;
    bool state;
    float linear_speed;
    float theta_speed;

    RobotTask(int robot_id, bool state, float linear_speed, float theta_speed) {
        this->robot_id = robot_id;
        this->state = state;
        this->linear_speed = linear_speed;
        this->theta_speed = theta_speed;
    }

    string make_message(){
        // TODO: return a string like this:
        // - [ROBOT_ID]
        // - [STATE]
        // - [linearSpeed]
        // - [linearSpeed >> 8]
        // - [thetaSpeed]
        // - [thetaSpeed >> 8]
    }
};

class Position{
    RobotTask calculate(SSL_DetectionRobot robot, QHash<int, SSL_DetectionRobot> our_robots,
                        QList<SSL_DetectionRobot> their_robots, SSL_DetectionBall ball){
        return RobotTask(robot.robot_id(), true, 0, 0);
    }
};

// this is a forward declarations for coach since Play and Coach refers to
// each other
class Coach;

class Play {
public:
    virtual void delegate_roles(Coach *coach)=0;
};

class Coach
{
public:
    virtual void send_transmission()=0;
    virtual void update(noplan_detection *detection, Commons::Color team_color)=0;

    // for each robot in 'player_positions' with a position given by 'actual_play'
    // run the decision making of each robot and return a hash with robot_id -> RobotTask,
    // being robotTask a plain object to encapsulate the move command to the robot.
    virtual QHash<int, RobotTask> make_decisions()=0;
    virtual void decide_play()=0;

    // hash with: robot_id -> name_position, easy way to debug.
    QHash<int, Position> player_positions;
    // hash with: robot_id -> detection, will be used for the decision-making methods
    QHash<int, SSL_DetectionRobot> our_robots;
    // list with: detection, list with oponent robots, will be used for the decision-making methods
    QList<SSL_DetectionRobot> their_robots;
    // self-explained
    SSL_DetectionBall ball;
    // actual play that coach is considering
    Play *actual_play;
};
#endif // COACH_H
