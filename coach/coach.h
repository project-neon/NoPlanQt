#ifndef COACH_H
#define COACH_H
#include "player.h"
#include "detection/noplan_detection.h"
#include <vector>
#include <QHash>

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

class Coach
{
public:
    virtual void create_robots(noplan_detection detection)=0;
    virtual void send_transmission()=0;
    virtual void update(noplan_detection detection)=0;
    virtual QHash<int, RobotTask> make_decisions()=0;
private:
    std::vector<Player> players;
};
#endif // COACH_H
