#include "match.h"
#include "noplan_detection.h"
#include <QApplication>
#include <QHash>
#include <QTextStream>

QTextStream out(stdout);

class DummyMatch : public Match {
public:
    QHash<int, SSL_DetectionRobot> players;

    void define_coach(Coach coach, noplan_detection detection) {
        this->coach = coach;
        std::vector<SSL_DetectionRobot> our_robots;
        if(this->team_color == Commons::BLUE) {
            our_robots = detection.blue_robots;
        }
        else{
            our_robots = detection.yellow_robots;
        }
        for(int i=0; i<our_robots.size(); i++) {
            SSL_DetectionRobot robot = our_robots[i];
            players[robot.robot_id()] = robot;
        }

    }
    // Faz iteração do Coach
    void loop(noplan_detection *detection) {
        if(players.contains(9)){
            out << players[9].robot_id() << endl;
        }
    }
    // Cria o coach e recebe dados da UI
    void setup() {

    }
};

class DummyCoach : public Coach {
public:
    void create_robots(noplan_detection detection) {

    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    SSLVisionClientThread vision_thread;
    vision_thread.start();

    DummyMatch my_match = DummyMatch();
    DummyCoach my_coach = DummyCoach();
    my_match.define_coach(my_coach, vision_thread.detection);
    while (true)
    {
        // TODO: |not working, tries to solve possible pointers
        // TODO: |or create a getter for detection object.
        my_match.loop(&vision_thread.detection);

    }
}
