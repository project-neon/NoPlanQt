#ifndef INTENTION_H
#define INTENTION_H

#include "coach/coach.h"

#include <QString>

#include <math/vector2.h>


class Intetion{
public:
    QString name;
    float weight;

    float MAX_ROBOT_SPEED = 999.f;

    Intetion(QString name, float weight);

    QList<float> compute(Vector2 position, float orientation);

    RobotTask computeFromIntention(float vx, float vy, float vtheta, float orientation) {
        Vector2 target_speed_vector = Vector2(vx, vy);

        float target_speed = target_speed_vector.Length();

        if (target_speed > this->MAX_ROBOT_SPEED) {
            target_speed = this->MAX_ROBOT_SPEED;
            target_speed_vector = Vector2::mult(target_speed_vector.Normalize(), this->MAX_ROBOT_SPEED);
        }

        Vector2 robot_world_speed = Vector2.rotate(target_speed_vector, -orientation);

        float linear = robot_world_speed.X;

        if (robot_world_speed.X < 0.f) {
            robot_world_speed.Y = -robot_world_speed.Y;
            robot_world_speed.X = -robot_world_speed.X;
        }

        float robot_angle_to_speed = -Vector2.angle(robot_world_speed);

        float speed_weight = 0.5f;
        float v_theta_weight = 0.5f;

        float angular = robot_angle_to_speed * 4 * speed_weight + vtheta * v_theta_weight;

        return RobotTask(-1, true, linear, angular);

    }

};

#endif
