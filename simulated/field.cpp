#include "field.h"

Field::Field(QGraphicsItem *parent, int x, int y, int real_width, int real_heigth)
    :QObject(), QGraphicsPixmapItem(parent), x(x), y(y), real_width(real_width), real_heigth(real_heigth){

    this->scale = Commons::MATCH_FIELD_WIDTH / real_width;

    setPixmap(QPixmap(":/img/fields/resources/field.png"));
    setTransformOriginPoint(Commons::MATCH_FIELD_WIDTH / 2, Commons::MATCH_FIELD_HEIGHT / 2);
    setPos(x, y);

}

Field::~Field() {}
