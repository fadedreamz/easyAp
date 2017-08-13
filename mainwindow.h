#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <memory>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QTextEdit * getLogWindow();

private:
    static MainWindow * thisInstance;
    Ui::MainWindow *ui;
    std::shared_ptr<QStringList> getWifiInterfaces();
    std::shared_ptr<QStringList> getAllInterfaces();
};

#endif // MAINWINDOW_H
