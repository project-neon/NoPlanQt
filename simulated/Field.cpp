#include "Field.h"

Field::Field(QGraphicsItem *parent, int x, int y, int real_width, int real_heigth)
    :QObject(), QGraphicsPixmapItem(parent), x(x), y(y), real_width(real_width), real_heigth(real_heigth){

    this->scale = Ui::MATCH_FIELD_WIDTH / real_width;

    setPixmap(QPixmap(":/img/fields/field.png"));
    setTransformOriginPoint(Ui::MATCH_FIELD_WIDTH / 2, Ui::MATCH_FIELD_HEIGHT / 2);
    setPos(x, y);

}

Field::~Field() {}
