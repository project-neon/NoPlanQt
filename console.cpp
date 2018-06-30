#include "console.h"

Console::Console(QTextEdit *console) : console(console) {}

void Console::debug(QString message) {


}

void Console::warning(QString message) {

    QString warning = "<br /> <p style='\'color=yellow\''>";
    QString warning_close = "</p>";

    this->console->insertHtml(warning + message + warning_close);

}

void Console::success(QString message) {

    QString success = "<br /> <p style='\'color=green\''>";
    QString success_close = "</p>";

    this->console->insertHtml(success + message + success_close);

}

void Console::error(QString message) {

    QString error = "<br /> <p style='\'color=red\''>";
    QString error_close = "</p>";

    this->console->insertHtml(error + message + error_close);

}
