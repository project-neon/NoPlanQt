#pragma once
#include "robot.h"

#include <QThread>
#include <ui/MainWindow.h>
#include <detection/noplan_detection.h>

class UpdateUIThread : public QThread {
protected:
    void run();
public:
    noplan_detection *detection;
    MainWindow *ui;
    QHash<int, Robot *> players;
    void set_robots(QHash<int, Robot *> players);
    UpdateUIThread(QObject *parent=0);
    void set_parameters(noplan_detection *detection, MainWindow *ui);

};
