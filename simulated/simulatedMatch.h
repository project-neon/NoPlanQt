#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QHash>
#include <QHashIterator>
#include <vector>
#include <QImage>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QThread>

#include <detection/noplan_detection.h>

#include <ui/MainWindow.h>

#include "field.h"
#include "robot.h"
#include "ball.h"

class SimulatedMatch : public QGraphicsView{


public:
    QGraphicsScene *scene;

    int right_side_score;
    int left_side_score;

    int team_in_left_side;
    int team_in_right_side;

    bool is_paused = false;

    QString message = "";

    QHash<int, Robot *> players;

    SimulatedMatch(QWidget *parent = 0);
    ~SimulatedMatch();

    void run();
    void add_player(Robot *robot);
    void add_ball(Ball *ball);
    void update(QString message);
    void pause();
    void invert_team_side();
    void update_score(Commons::Color team);
    int translate_position_x(int x);
    int translate_position_y(int y);

};
