#include "field.h"

Field::Field(QGraphicsItem *parent, int x, int y, int real_width, int real_heigth)
    :QObject(), QGraphicsPixmapItem(parent), x(x), y(y), real_width(real_width), real_heigth(real_heigth){

    this->m_scale = Commons::MATCH_FIELD_WIDTH / real_width;

    QPixmap field(":/img/fields/resources/field.png");
    QPixmap scaled = field.scaled(QSize(Commons::WINDOW_WIDTH, Commons::WINDOW_HEIGHT));

    setPixmap(scaled);
    setTransformOriginPoint(Commons::MATCH_FIELD_WIDTH / 2, Commons::MATCH_FIELD_HEIGHT / 2);
    setPos(x, y);

}

Field::~Field() {}
