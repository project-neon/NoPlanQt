#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <string>
#include <QString>

#include "../commons.h"

class Ball : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

private:

    int id;

public:

    int x, y, speed;
    Commons::Sizes size = Commons::MEDIUM;

    Ball(QGraphicsPixmapItem *parent = 0, int id = 0, int x = 0, int y = 0, int speed = 0, Commons::Sizes size = Commons::VERY_SMALL);
    ~Ball();


    int get_id() const;
    void set_id(int id);

signals:

public slots:

    void update(int x = 0, int y = 0, int speed = 0);

};
