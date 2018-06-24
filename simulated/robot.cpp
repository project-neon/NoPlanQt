#include "robot.h"

Robot::Robot(QGraphicsPixmapItem *parent, int id, bool state, int m_x, int m_y, Commons::Color team, Commons::Size size, float linear_speed, float theta_speed)
    :QObject(), QGraphicsPixmapItem(parent), id(id), state(state), m_x(m_x), m_y(m_y), team(team), size(size), linear_speed(linear_speed), theta_speed(theta_speed) {

    QString tmp = "";

    if (team == Commons::BLUE) {

        tmp = (":/img/robots/resources/blue_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");


    } else if (team == Commons::YELLOW) {

        tmp = QString(":/img/robots/resources/yellow_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");

    } else {

        tmp = QString(":/img/robots/resources/unknow_")
                + QString::number(this->size)
                + QString("x")
                + QString::number(this->size)
                + QString(".png");

    }

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);


    setFlag(QGraphicsItem::ItemIsFocusable);
    setPixmap(QPixmap(tmp));
    setTransformOriginPoint(this->size / 2, this->size / 2);
    setRotation(this->theta_speed);

    if (this->m_x > Commons::FIELD_PLAYABLE_WIDTH - this->size / 2) {
        this->m_x = this->m_x - (Commons::FIELD_PLAYABLE_WIDTH - (this->m_x + this->size / 2));
    } else if (this->m_x < (Commons::MATCH_FIELD_WIDTH - (Commons::FIELD_PLAYABLE_WIDTH + this->size / 2))) {
        this->m_x = Commons::FIELD_PLAYABLE_WIDTH + this->size / 2;
    } else {
        this->m_y = this->m_y;
    }

    if (this->m_y > Commons::FIELD_PLAYABLE_HEIGHT - this->size / 2) {
        this->m_y = this->m_y - (Commons::FIELD_PLAYABLE_HEIGHT - (this->m_y + this->size / 2));
    } else if (this->m_y < (Commons::MATCH_FIELD_HEIGHT - (Commons::FIELD_PLAYABLE_HEIGHT + this->size / 2))) {
        this->m_y = Commons::FIELD_PLAYABLE_HEIGHT + this->size / 2;
    } else {
        this->m_y = this->m_y;
    }

    setPos(this->m_x, this->m_y);
}

Robot::~Robot() {}


void Robot::update(int id, bool state, float linear_speed, float theta_speed) {

    this->id            = id;
    this->state         = state;
    this->linear_speed  = linear_speed;
    this->theta_speed   = theta_speed;

}

void Robot::move() {

    setRotation(this->theta_speed);

    if (this->state) {

        if (this->m_x < (Commons::FIELD_PLAYABLE_WIDTH - this->size / 2) && this->m_x > ((Commons::MATCH_FIELD_WIDTH - Commons::FIELD_PLAYABLE_WIDTH) + this->size)) {
            this->m_x += (round(cos(this->theta_speed)) * this->linear_speed);
        }
        if (this->m_y < (Commons::FIELD_PLAYABLE_HEIGHT - this->size / 2) && this->m_y > ((Commons::MATCH_FIELD_HEIGHT - Commons::FIELD_PLAYABLE_HEIGHT) + this->size)) {
            this->m_y += (round(sin(this->theta_speed)) * this->linear_speed);
        }

        setPos(this->m_x, this->m_y);

    }

}

int Robot::get_id() const {
    return this->id;
}

