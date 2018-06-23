#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <string>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
#include <QtMath>
#include <cmath>

#include "Commons.h"

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

    RobotTeamColor team;
    Sizes size;

    float linear_speed;
    float theta_speed;


    Robot(QGraphicsPixmapItem *parent = 0, int id = 0, bool state = 0, int m_x = 0, int m_y = 0, RobotTeamColor team = RobotTeamColor::BLUE, Sizes size = Sizes::VERY_SMALL, float linear_speed = 0, float theta_speed = 0);
    ~Robot();

    int get_id() const;
    void update(int id = 0, bool state = 0, float linear_speed = 0, float theta_speed = 0);

public slots:

    void move();

};
