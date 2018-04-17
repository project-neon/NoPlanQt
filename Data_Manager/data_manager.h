#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

class SSLVisionClientThread : public QThread
{
protected:
    void run();
public:
    SSLVisionClientThread(QObject* parent = 0){}
    ~SSLVisionClientThread(){}

    SSL_DetectionFrame detection;
};

#endif // DATA_MANAGER_H
