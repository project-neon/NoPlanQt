#include "coach/coach.h"

class SimplePlay : public Play{
    void delegate_roles(Coach *coach){
        for(QHash<int, SSL_DetectionRobot>::iterator i=coach->our_robots.begin();i!=coach->our_robots.end();++i)
        {
            SSL_DetectionRobot robot_detection = (i.value());
            int robot_id = (i.key());
            coach->player_positions[robot_id] = Position();
        }
    }
};
