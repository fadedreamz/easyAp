#include "mainwindow.h"
#include <QApplication>

#include "iscdhcpparseengine.h"

void test() {
    std::string testString = std::string("subnet 192.168.5.0 netmask 255.255.255.0 {\n"
                                         "range 192.168.5.100 192.168.5.200;\n"
                                         "#  option routers rtr-239-0-1.example.org, rtr-239-0-2.example.org;\n"
                                       "}");
    IscDHCPParseEngine engine;
    engine.parseSubNetConf(testString);
}

int main(int argc, char *argv[])
{
    test();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
