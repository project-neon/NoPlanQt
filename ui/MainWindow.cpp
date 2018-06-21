#include <QFont>
#include <QFontDatabase>

#include "MainWindow.h"
#include "ui_MainWindow.h"

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

}

MainWindow::~MainWindow() {
    delete ui;
}
