#include "subnetconf.h"
#include <arpa/inet.h>
#include <QDebug>

using namespace std;

SubNetConf::SubNetConf()
{

}

SubNetConf::~SubNetConf() {

}

bool SubNetConf::isIpAddr(std::string debugName, std::string & ip)
{
    uint8_t buff[sizeof(struct in6_addr)];
    if (inet_pton(AF_INET, ip.c_str(), buff) != 1) {
        qDebug() << "wrong address format supplied for " << debugName.c_str();
        return false;
    }
    return true;
}

string SubNetConf::getNetwork()
{
    return this->network;
}

void SubNetConf::setNetwork(string network)
{
    if (isIpAddr("network", network)) {
        this->network = network;
    }
}

string SubNetConf::getNetmask()
{
    return this->netmask;
}

void SubNetConf::setNetmask(string netmask) {
    if (isIpAddr("netmask", netmask)) {
        this->netmask = netmask;
    }
}

std::string SubNetConf::getStartIp()
{
    return this->startIP;
}

void SubNetConf::setStartIp(std::string startIP) {
    if (isIpAddr("start-ip", startIP)) {
        this->startIP = startIP;
    }
}

std::string SubNetConf::getEndIp() {
    return this->endIP;
}

void SubNetConf::setEndIp(std::string endIp) {
    if (isIpAddr("end-ip", endIp)) {
        this->endIP = endIp;
    }
}

shared_ptr<SubNetConf> parseSubNetConfig(string config)
{
    return shared_ptr<SubNetConf>(nullptr);
}
