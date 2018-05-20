#include "match.h"
#include "noplan_detection.h"
#include <QApplication>
class DummyMatch : public Match {
public:
    void define_coach(Coach coach) {
        this->coach = coach;
    }
    // Faz iteração do Coach
    void loop(noplan_detection detection) {

    }
    // Cria o coach e recebe dados da UI
    void setup() {

    }
};

class DummyCoach : public Coach {
public:
    void create_robots(noplan_detection detection) {
        // popular a lista de robos do coach pela team_color
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    SSLVisionClientThread vision_thread;
    vision_thread.start();

    DummyMatch my_match = DummyMatch();
    DummyCoach my_coach = DummyCoach();
    my_match.define_coach(my_coach);
    while (true)
    {
        my_match.loop(vision_thread.detection);
    }
}
