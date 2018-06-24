#pragma once

#include <QThread>

#include "noplan_detection.h"
#include "commons.h"

class SSLVisionClientThread : public QThread {

protected:
    void run();

public:
    SSLVisionClientThread(QObject* parent = 0){}
    ~SSLVisionClientThread(){}

    noplan_detection detection;
    Commons::FieldSide orientation = Commons::RIGHT;
    Commons::Color color = Commons::BLUE;

    // é setter para a orientação do campo, sera chamado pela
    // interface quando houver troca de campo.
    void changeFieldSize(Commons::FieldSide orientation);
    void setTeamColor(Commons::Color color);

};
