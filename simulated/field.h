#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>

#include "../commons.h"

class Field : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:

    int x, y;
    int real_width, real_heigth, m_scale;

    Field(QGraphicsItem *parent = 0);
    Field(QGraphicsItem *parent = 0, int x = 0, int y = 0, int real_width = 1700, int real_heigth = 1300);
    ~Field();

};
