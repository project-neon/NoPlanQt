#include <QFont>
#include <QFontDatabase>
#include <QPushButton>

#include <simulated/simulatedMatch.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <QTextStream>

SimulatedMatch* match;

QTextStream _out(stdout);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initial configs:
    this->team_color = static_cast<Commons::Color>(ui->cmb_color->currentIndex());

    match = new SimulatedMatch();
    QGraphicsScene* scene = match->scene;

//    Robot *robot1 = new Robot(0, 1, 1, 200, 100, Commons::BLUE, Commons::SUPER_VERY_SMALL, 41, 180);
//    Ball *ball = new Ball(0, 32, 300, 150, 10, Commons::SUPER_VERY_SMALL);


    match->update("1, 1, 20, 90");


//    match->scene->addItem(robot1);
//    match->scene->addItem(ball);

//    match->add_player(robot1);
//    match->add_ball(ball);

    ui->simulated_match->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->simulated_match->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->simulated_match->setScene(scene);

    // Actions

    connect(ui->btn_real_match, SIGNAL(clicked()), this, SLOT(startRealMatch()));

}

void MainWindow::startRealMatch() {
    this->vision_thread = new SSLVisionClientThread();
    this->vision_thread->start();



}

MainWindow::~MainWindow() {
    delete ui;
    delete vision_thread;
}
