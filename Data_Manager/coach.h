#ifndef COACH_H
#define COACH_H
#include "player.h"
#include <vector>
#include "noplan_detection.h"

class Coach
{
public:
    void create_robots(noplan_detection detection);
    void send_transmission();
    void update();
private:
    std::vector<Player> players;
};
#endif // COACH_H
