#include "ball.h"

Ball::Ball(QGraphicsPixmapItem *parent, int id, int x, int y, int speed, Commons::Size size)
    : QObject(), QGraphicsPixmapItem(parent), id(id), x(x), y(y), speed(speed), size(size) {

    QString tmp = QString(":/img/balls/resources/ball_")
            + QString::number(this->size)
            + QString("x")
            + QString::number(this->size)
            + QString(".png");

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(Commons::TIME_TO_UPDATE);

    setPixmap(QPixmap(tmp));
    setTransformOriginPoint(this->size / 2, this->size / 2);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setX(this->x);
    setY(this->y);

}

Ball::~Ball() {}


void Ball::update(int x, int y, int speed) {

    this->x += x;
    this->y += y;
    this->speed = speed;

}

void Ball::move() {
    setPos(this->x, this->y);
}

int Ball::get_id() const {
    return this->id;
}

void Ball::set_id(int id) {
    this->id = id;
}
