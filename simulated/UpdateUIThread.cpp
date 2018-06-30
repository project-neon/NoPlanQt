#include "UpdateUIThread.h"


void UpdateUIThread::run() {
    for (int i = 0; i < Commons::NUMBER_OF_ROBOTS; i++) {
        //int robot_id = data[0].toInt();
        //Robot *robot = this->players.value(robot_id);
        // RODAR O ALGORITMO DE ESTRATEGIA E ENVIAR O RESULTADO PARA O UPDATE
        //robot->update();
    }
    //this->robot->update(1, 1, 10, 90);
}

UpdateUIThread::UpdateUIThread(QObject *parent) {}

void UpdateUIThread::set_robots(QHash<int, Robot *> players) {
    this->players = players;
}
