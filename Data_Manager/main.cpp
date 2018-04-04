#include <QCoreApplication>
#include <QtGui>
#include <QApplication>

#include "robocup_ssl_client.h"

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <QTextStream>

QTextStream out(stdout);

bool runApp = true;

inline void Sleep(double sec)
{
   usleep((int)(sec * 1E6));
}

class MyThread : public QThread
{
protected:
    void run()
    {
        static const double minDuration = 0.01; //100FPS
        RoboCupSSLClient client;

        client.open(false);
        SSL_WrapperPacket packet;
        while(runApp) {
            while (client.receive(packet)) {
                if (packet.has_detection()) {
                    SSL_DetectionFrame detection = packet.detection();
                    out << "teste" << endl;
                    // view->updateDetection(detection);
                }
                if (packet.has_geometry()) {
                    // view->updateFieldGeometry(packet.geometry().field());
                }
            }
            Sleep(minDuration);
        }
    }

public:
    MyThread(QObject* parent = 0){}
    ~MyThread(){}
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MyThread thread;
    thread.start();
    int retVal = app.exec();
    runApp = false;
    thread.wait();
    return retVal;
}
