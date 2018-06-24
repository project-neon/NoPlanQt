#include "simulatedMatch.h"

Field *field;

SimulatedMatch::SimulatedMatch(QWidget *parent)
    : QGraphicsView(parent) {

    //match control variables
    this->right_side_score = 0;
    this->left_side_score  = 0;

    this->team_in_left_side  = Commons::BLUE;
    this->team_in_right_side = Commons::YELLOW;

    //scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, Commons::WINDOW_WIDTH, Commons::WINDOW_HEIGHT);

    //field
    field = new Field(0, 0, 0, Commons::MATCH_FIELD_WIDTH, Commons::MATCH_FIELD_HEIGHT);
    scene->addItem(field);

    //view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Commons::WINDOW_WIDTH, Commons::WINDOW_HEIGHT);
    setScene(scene);
    setWindowTitle("Partida Simulada - Project Neon");

}

SimulatedMatch::~SimulatedMatch() {
    delete scene;
    delete this;
}

int SimulatedMatch::translate_position_x(int x) {
   return x * field->scale + Commons::FIELD_PLAYABLE_WIDTH / 2;
}

int SimulatedMatch::translate_position_y(int y) {
    return y * field->scale + Commons::FIELD_PLAYABLE_HEIGHT / 2;
}

void SimulatedMatch::update(QString message) {}

void SimulatedMatch::update_score(Commons::Color team) {

    if (team == this->team_in_right_side) {
        this->right_side_score += 1;
    } else if (team == this->team_in_left_side) {
        this->left_side_score += 1;
    } else {
        qDebug() << "This team does not exist! Please select Commons::BLUE or Commons::YELLOW.";
    }

}

void SimulatedMatch::pause() {

    if (this->is_paused) {
        this->is_paused = false;
    } else {
        this->is_paused = true;
    }

}

void SimulatedMatch::add_player(Robot *robot) {

    if (!this->players.contains(robot->get_id())) {

        this->players.insert(robot->get_id(), robot);
        this->scene->addItem(robot);
        qDebug() << "Robo " << robot->get_id() << " adicionado com sucesso!";

    } else {

        qDebug() << "Robot " << robot->get_id() << " ja foi inserido na partida!";
    }

}

void SimulatedMatch::invert_team_side() {

    int tmp = this->team_in_left_side;
    this->team_in_left_side = this->team_in_right_side;
    this->team_in_right_side = tmp;

    qDebug() << "Lados invertidos. Time no lado esquerdo: " << team_in_left_side << "| Time do lado direito: " << team_in_right_side;

}

void SimulatedMatch::add_ball(Ball *ball) {

    this->scene->addItem(ball);
    qDebug() << "Bola criada, e adicionada na partida!";

}
