#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <string>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
//#include <QMath>
#include <cmath>
#include "commons.h"

class Robot : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

private:

    int id;

public:

    enum RobotTeamColor {

        BLUE    = 0,
        YELLOW

    };

    bool state;

    int m_x;
    int m_y;

    Commons::Color team;
    Commons::Size size;

    float linear_speed;
    float theta_speed;


    Robot(QGraphicsPixmapItem *parent = 0, int id = 0, bool state = 0, int m_x = 0, int m_y = 0, Commons::Color team = Commons::BLUE, Commons::Size size = Commons::VERY_SMALL, float linear_speed = 0, float theta_speed = 0);
    ~Robot();

    int get_id() const;
    void update(int id = 0, bool state = 0, float linear_speed = 0, float theta_speed = 0);

public slots:

    void move();

};
