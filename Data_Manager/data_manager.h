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
    enum FieldSide {RIGHT, LEFT};
    FieldSide orientation = RIGHT;

    enum Color {YELLOW, BLUE};
    Color color = BLUE;

    // é setter para a orientação do campo, sera chamado pela
    // interface quando houver troca de campo.
    void changeFieldSize(FieldSide orientation);
    void setTeamColor(Color color);

};

#endif // DATA_MANAGER_H
