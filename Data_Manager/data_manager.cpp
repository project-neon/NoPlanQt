#include <QCoreApplication>
#include <QtGui>
#include <QApplication>

#include "robocup_ssl_client.h"
#include "noplan_detection.h"
#include "data_manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <QTextStream>


bool runApp = true;

inline void Sleep(double sec)
{
   usleep((int)(sec * 1E6));
}

void SSLVisionClientThread::setTeamColor(Color color) {
    this->color = color;
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
                SSL_DetectionFrame rawDetection = packet.detection();
                detection = noplan_detection();
                if (orientation == left)
                {
                    int blue_team_size = rawDetection.robots_blue_size();
                    std::vector<SSL_DetectionRobot>::iterator it = detection.blue_robots.begin();
                    for (int i=0; i < blue_team_size; i++) {
                        SSL_DetectionRobot robot = rawDetection.robots_blue(i);
                        robot.set_x(-robot.x());
                        robot.set_y(-robot.y());
                        ++it;
                        detection.blue_robots.insert(it, robot);
                    }

                    int yellow_team_size = rawDetection.robots_yellow_size();
                    it = detection.yellow_robots.begin();
                    for (int i=0; i < yellow_team_size; i++) {
                        SSL_DetectionRobot robot = rawDetection.robots_yellow(i);
                        robot.set_x(-robot.x());
                        robot.set_y(-robot.y());
                        ++it;
                        detection.yellow_robots.insert(it, robot);
                    }
                }
            }
            if (packet.has_geometry()) {
                // view->updateFieldGeometry(packet.geometry().field());
            }
        }
        Sleep(minDuration);
    }
}
