#include "match/match.h"
#include "detection/noplan_detection.h"
#include <QApplication>
#include <QHash>
#include <QTextStream>
#include <play/simplePlay.cpp>
#include "ui/MainWindow.h"


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
        this->coach->update(detection, team_color);

        this->coach->decide_play();

        this->coach->actual_play->delegate_roles(this->coach);

        QHash<int, RobotTask*> decisions = this->coach->make_decisions();
    }
    // Cria o coach e recebe dados da UI
    void setup() {

    }
};

class DummyCoach : public Coach {
public:
    SimplePlay simplePlay;

    DummyCoach() {
        simplePlay = SimplePlay();
    }

    void update(noplan_detection *detection, Commons::Color team_color){

        this->ball = detection->ball;

        std::vector<SSL_DetectionRobot> *our_robots_list;
        std::vector<SSL_DetectionRobot> *their_robots_list;
        if(team_color == Commons::BLUE) {
            our_robots_list = &detection->blue_robots;
            their_robots_list = &detection->yellow_robots;
        }
        else{
            our_robots_list = &detection->yellow_robots;
            their_robots_list = &detection->blue_robots;
        }

        for(int i=0; i<our_robots_list->size(); i++) {
            SSL_DetectionRobot robot = (*our_robots_list)[i];
            this->our_robots[robot.robot_id()] = robot;
        }

        for(int i=0; i<their_robots_list->size(); i++) {
            SSL_DetectionRobot robot = (*our_robots_list)[i];
            this->their_robots.append(robot);
        }
    }

    QHash<int, RobotTask*> make_decisions() {
        QHash<int, RobotTask*> decision;
        for(QHash<int, SSL_DetectionRobot>::iterator i=this->our_robots.begin();i!=this->our_robots.end();++i)
        {
            SSL_DetectionRobot robot_detection = (i.value());
            int robot_id = (i.key());
            RobotTask task = this->player_positions[robot_id].calculate(
                        &robot_detection, &this->our_robots, &this->their_robots, &this->ball
            );

            decision[robot_id] = &task;
            decision[robot_id]->debug_message();
        }

        return decision;
    }

    void decide_play() {
        this->actual_play = &simplePlay;
    }

    void send_transmission() {
    }
};

int main(int argc, char **argv)
{

    QApplication app(argc, argv);
//    TODO: Inicializa apenas quando
//    SSLVisionClientThread vision_thread;
//    vision_thread.start();

    MainWindow w;
    w.show();

//    DummyMatch my_match = DummyMatch();
//    DummyCoach my_coach = DummyCoach();
//    my_match.define_coach(&my_coach, &vision_thread.detection);
    return app.exec();
}
