#include <QFont>
#include <QFontDatabase>

#include <simulated/simulatedMatch.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

SimulatedMatch* match;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    match = new SimulatedMatch();
    QGraphicsScene* scene = match->scene;


    Robot *robot1 = new Robot(0, 1, 1, 200, 100, Commons::BLUE, Commons::SUPER_VERY_SMALL, 41, 180);
    Ball *ball = new Ball(0, 32, 300, 150, 10, Commons::SUPER_VERY_SMALL);

    match->scene->addItem(robot1);
    match->scene->addItem(ball);

    ui->simulated_match->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->simulated_match->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->simulated_match->setScene(scene);

}

MainWindow::~MainWindow() {
    delete ui;
}
