#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <memory>
#include "interfacemanager.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->resize(width(), height());
    ui->tabWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    shared_ptr<QStringList> items = getWifiInterfaces();
    for (int i=0; i< items->size(); i++) {
       ui->comboBox->addItem(items->at(i));
    }

    shared_ptr<QStringList> allIfList = getAllInterfaces();
    for(int i=0; i < allIfList->size(); i++) {
        ui->comboBox_2->addItem(allIfList->at(i));
    }

    ui->tabWidget->resize(ui->centralWidget->width() - 20, ui->centralWidget->height() - 20);
    ui->tabWidget->setGeometry(10, 10, ui->centralWidget->width() - 20, ui->centralWidget->height() - 20);

    ui->tab->
}

MainWindow::~MainWindow()
{
    delete ui;
}

shared_ptr<QStringList> MainWindow::getWifiInterfaces()
{
    shared_ptr<QStringList> list = shared_ptr<QStringList>(new QStringList);
    shared_ptr<InterfaceManager> ifManager = shared_ptr<InterfaceManager>(new InterfaceManager());
    shared_ptr<vector<string>> ifList = ifManager->getWirelessInterfaces();
    for(auto it = ifList->begin(); it != ifList->end(); it++) {
        list->append(QString((*it).c_str()));
    }
    return list;
}

std::shared_ptr<QStringList> MainWindow::getAllInterfaces() {
    shared_ptr<QStringList> list = shared_ptr<QStringList>(new QStringList);
    shared_ptr<InterfaceManager> ifManager = shared_ptr<InterfaceManager>(new InterfaceManager());
    shared_ptr<vector<string>> ifList = ifManager->getAllInterfaces();
    for(auto it = ifList->begin(); it != ifList->end(); it++) {
        list->append(QString((*it).c_str()));
    }
    return list;
}
