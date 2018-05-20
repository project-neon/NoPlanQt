#ifndef COACH_H
#define COACH_H
#include "player.h"
#include <vector>

class Coach
{
public:
    void create_robots();
    void send_transmission();
    void update();
private:
    std::vector<Player> players;
};
#endif // COACH_H
