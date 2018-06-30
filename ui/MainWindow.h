#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <match/match.h>
#include <detection/noplan_detection.h>
#include <simulated/UpdateUIThread.h>
#include <simulated/simulatedMatch.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void startRealMatch();

public:
    SSLVisionClientThread *vision_thread;

    //UpdateUIThread *ui_thread;

    Commons::Color team_color;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
