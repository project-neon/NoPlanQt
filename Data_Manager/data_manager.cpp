#include <QCoreApplication>
#include <QtGui>
#include <QApplication>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <QTextStream>
#include <vector>

#include "robocup_ssl_client.h"
#include "noplan_detection.h"
#include "data_manager.h"
#include "commons.h"

bool run_app = true;

inline void Sleep(double sec) {
   usleep((int)(sec * 1E6));
}

void SSLVisionClientThread::setTeamColor(Commons::Color color) {
    this->color = color;
}

void SSLVisionClientThread::run() {

    static const double min_duration = 0.01; //100FPS

    RoboCupSSLClient client;
    client.open(false);

    SSL_WrapperPacket packet;

    while(run_app) {

        while (client.receive(packet)) {

            if (packet.has_detection()) {

                SSL_DetectionFrame rawDetection = packet.detection();
                detection = noplan_detection();

                int blue_team_size = rawDetection.robots_blue_size();
                for (int i=0; i < blue_team_size; i++) {

                    SSL_DetectionRobot robot = rawDetection.robots_blue(i);
                    if (orientation == Commons::LEFT) {

                        robot.set_x(-robot.x());
                        robot.set_y(-robot.y());
                        robot.set_orientation(robot.orientation() + M_PI);

                    }

                    detection.blue_robots.push_back(robot);

                }

                int yellow_team_size = rawDetection.robots_yellow_size();
                for (int i=0; i < yellow_team_size; i++) {

                    SSL_DetectionRobot robot = rawDetection.robots_yellow(i);
                    if (orientation == Commons::LEFT) {

                        robot.set_x(-robot.x());
                        robot.set_y(-robot.y());
                        robot.set_orientation(robot.orientation() + M_PI);

                    }

                    detection.yellow_robots.push_back(robot);

                }

            }

            if (packet.has_geometry()) {
                // view->updateFieldGeometry(packet.geometry().field());
            }

        }

        Sleep(min_duration);

    }

}
