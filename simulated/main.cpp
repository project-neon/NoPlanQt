#include <QApplication>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QTimer>
#include <QThread>

#include "simulatedMatch.h"
#include "robot.h"
#include "Commons.h"

SimulatedMatch *match;


class Teste : public QThread {

protected:
    void run() {
        this->robot->update(1, 1, 10, 90);
    }

public:
    Robot *robot;
    Teste(QObject *parent = 0) {}
    void set_robot(Robot *robot) {
        this->robot = robot;
    }

};
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    match = new SimulatedMatch();

    Robot *robot1 = new Robot(0, 1, 1, 200, 100, Robot::Commons::Color::BLUE, Sizes::VERY_SMALL, 41, 180);
    //robot1->config(Robot::RobotTeamColor::BLUE, Sizes::VERY_SMALL);
    Robot *robot2 = new Robot(0, 2, 0, 200, 256, Robot::Commons::Color::BLUE, Sizes::VERY_SMALL, 10, 180);
    //robot2->config(Robot::RobotTeamColor::BLUE, Sizes::VERY_SMALL);
    Robot *robot3 = new Robot(0, 3, 0, 200, 512, Robot::Commons::Color::BLUE, Sizes::VERY_SMALL, 55, 180);
    //robot3->config();
    Robot *robot4 = new Robot(0, 4, 0, 650, 100, Robot::Commons::Color::YELLOW, Sizes::VERY_SMALL, 0, 0);
   // robot4->config(Robot::RobotTeamColor::YELLOW, Sizes::VERY_SMALL);
    Robot *robot5 = new Robot(0, 5, 0, 650, 256, Robot::Commons::Color::YELLOW, Sizes::VERY_SMALL, 0, 0);
    //robot5->config(Robot::RobotTeamColor::YELLOW, Sizes::VERY_SMALL);
    Robot *robot6 = new Robot(0, 6, 0, 650, 512,Robot::Commons::Color::YELLOW, Sizes::VERY_SMALL, 0, 0);
    //robot6->config(Robot::RobotTeamColor::YELLOW, Sizes::VERY_SMALL);

    Ball *ball = new Ball(0, 32, 300, 150, 10, Sizes::VERY_SMALL);
    Teste teste;
    teste.start();
    teste.set_robot(robot1);

    match->add_player(robot1);
    match->add_player(robot2);
    match->add_player(robot3);
    match->add_player(robot4);
    match->add_player(robot5);
    match->add_player(robot6);
    match->add_player(robot6);

    match->add_ball(ball);

    match->show();


    return a.exec();

}
