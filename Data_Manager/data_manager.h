#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include "noplan_detection.h"

class SSLVisionClientThread : public QThread
{
protected:
    void run();
public:
    SSLVisionClientThread(QObject* parent = 0){}
    ~SSLVisionClientThread(){}

    noplan_detection detection;
    // RIGHT: do not reverse the coordinates
    // LEFT: reverse the coordinates
    enum FieldSide {right, left};
    FieldSide orientation = left;

    enum Color {yellow, blue};
    Color color = blue;
    // é setter para a orientação do campo, sera chamado pela
    // interface quando houver troca de campo.
    void changeFieldSize(FieldSide orientation);
    void setTeamColor(Color color);

};

#endif // DATA_MANAGER_H
