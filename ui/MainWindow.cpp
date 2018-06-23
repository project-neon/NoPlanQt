#include <QFont>
#include <QFontDatabase>

#include <simulated/SimulatedMatch.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"

SimulatedMatch* match;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //Carregando fonte
    /*int id = QFontDatabase::addApplicationFont(":/fonts/kenvector_future.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);

    QStringList colors =(QStringList() << "Selecione uma opção" << "Yellow" << "Blue");
    ui->cmb_color->addItems(colors);

    QStringList sides =(QStringList() << "Selecione uma opção" << "Right" << "Left");
    ui->cmb_side->addItems(sides);*/

    match = new SimulatedMatch();
    QGraphicsScene* scene = match->scene;
    ui->simulated_match->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
}
