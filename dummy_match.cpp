#include "match/match.h"
#include "detection/noplan_detection.h"
#include <QApplication>
#include <QHash>
#include <QTextStream>

QTextStream out(stdout);

class DummyMatch : public Match {
public:
    QHash<int, SSL_DetectionRobot> players;

    void define_coach(Coach *coach, noplan_detection *detection) {
        this->coach = coach;
        std::vector<SSL_DetectionRobot> our_robots;
        if(this->team_color == Commons::BLUE) {
            our_robots = detection->blue_robots;
        }
        else{
            our_robots = detection->yellow_robots;
        }
        for(int i=0; i<our_robots.size(); i++) {
            SSL_DetectionRobot robot = our_robots[i];
            players[robot.robot_id()] = robot;
        }

    }
    // Faz iteração do Coach
    void loop(noplan_detection *detection) {
        out << "ball:" << detection->ball.x() << "," << detection->ball.y() << endl;
        std::vector<SSL_DetectionRobot> *our_robots;
        if(this->team_color == Commons::BLUE) {
            our_robots = &detection->blue_robots;
        }
        else{
            our_robots = &detection->yellow_robots;
        }
        for(int i=0; i<our_robots->size(); i++) {
            SSL_DetectionRobot robot = (*our_robots)[i];
            players[robot.robot_id()] = robot;
        }

        QHash<int, RobotTask> decisions = this->coach->make_decisions();
    }
    // Cria o coach e recebe dados da UI
    void setup() {

    }
};

class DummyCoach : public Coach {
public:
    void create_robots(noplan_detection detection) {

    }

    void send_transmission(){}

    void update(noplan_detection detection){}

    QHash<int, RobotTask> make_decisions() {
        QHash<int, RobotTask> decision;
        return decision;
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    SSLVisionClientThread vision_thread;
    vision_thread.start();

    DummyMatch my_match = DummyMatch();
    DummyCoach my_coach = DummyCoach();
    my_match.define_coach(&my_coach, &vision_thread.detection);
    while (true)
    {
        my_match.loop(&vision_thread.detection);
    }
}
