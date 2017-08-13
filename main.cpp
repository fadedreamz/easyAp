#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "idhcpparseengine.h"
#include "logger.h"
#include "sstream"
#include <thread>

void test() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::string testString = std::string("subnet 192.168.5.0 netmask 255.255.255.0 {\n"
                                         "range 192.168.5.100 192.168.5.200;\n"
                                         "#  option routers rtr-239-0-1.example.org, rtr-239-0-2.example.org;\n"
                                       "}");
    std::shared_ptr<IDHCPParseEngine> engine = IDHCPParseEngine::getEngineByDriverName(std::string("isc-dhcp-server"));
    if (engine == nullptr) return;
    std::shared_ptr<SubNetConf> conf = engine->parseSubNetConf(testString);
    std::stringstream log;
    log << "network = " << conf->getNetwork().c_str() << ", netmask = " << conf->getNetmask().c_str() << std::endl;
    log << "serving range " << conf->getStartIp().c_str() << " to " << conf->getEndIp().c_str() << std::endl;
    Logger::Log(log.str().c_str());
}

int main(int argc, char *argv[])
{
    std::thread t(test);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
