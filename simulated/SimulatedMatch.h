#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QHash>
#include <QHashIterator>
#include <QString>
#include <vector>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QTextStream>
#include <QPushButton>

#include "Field.h"
#include "Robot.h"
#include "Ball.h"

class SimulatedMatch : public QGraphicsView {

public:

    QGraphicsScene *scene;

    int right_side_score;
    int left_side_score;

    int team_in_left_side;
    int team_in_right_side;

    bool is_paused = false;

    QHash<int, Robot *> players;

    SimulatedMatch(QWidget *parent = 0);
    ~SimulatedMatch();

    void init();
    void add_player(Robot *robot);
    void add_ball(Ball *ball);
    void update(QString message);
    void pause();
    void invert_team_side();
    void update_score(Robot::RobotTeamColor team);
    int translate_position_x(int x);
    int translate_position_y(int y);

};
