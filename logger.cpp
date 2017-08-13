#include "logger.h"
#include "mainwindow.h"
#include <QApplication>

Logger::Logger()
{

}

void Logger::Log(const char * str) {
    QTextEdit * window = MainWindow::getLogWindow();
    QString fullText = QString(str) + QString("\n") + window->toPlainText();
    QObject signalSource;
    QObject::connect(&signalSource, &QObject::destroyed, QApplication::instance(), [=](QObject *) {
       MainWindow::getLogWindow()->append(fullText);
    });
    emit window->update();
}
