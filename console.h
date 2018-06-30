#pragma once

#include<QWidget>
#include<QString>
#include<QTextEdit>

class Console {

private:
    QTextEdit *console;

public:

    enum Configs {
        TABS = 4,
        LINE_JUMP = 2
    };

    enum MessageType {
        NORMAL_MESSAGE = 0,
        ERROR_MESSAGE,
        WARNING_MESSAGE,
        SUCCESS_MESSAGE
    };

    QString generateMessage(Configs tabs, Configs line_jump, int type);
    void debug(QString message);
    void warning(QString message);
    void error(QString message);
    void success(QString message);

    Console(QTextEdit *console);
    ~Console();
};
