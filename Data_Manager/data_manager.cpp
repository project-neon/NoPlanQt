#include <QCoreApplication>
#include <QtGui>
#include <QApplication>

#include "robocup_ssl_client.h"
#include "data_manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <QTextStream>

//QTextStream out(stdout);

bool runApp = true;

inline void Sleep(double sec)
{
   usleep((int)(sec * 1E6));
}

void SSLVisionClientThread::run()
{
    static const double minDuration = 0.01; //100FPS
    RoboCupSSLClient client;

    client.open(false);
    SSL_WrapperPacket packet;
    while(runApp) {
        while (client.receive(packet)) {
            if (packet.has_detection()) {
                detection = packet.detection();
                //out << "teste" << endl;
                // view->updateDetection(detection);
            }
            if (packet.has_geometry()) {
                // view->updateFieldGeometry(packet.geometry().field());
            }
        }
        Sleep(minDuration);
    }
}
