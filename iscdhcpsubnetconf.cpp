#include "iscdhcpsubnetconf.h"

using namespace std;

IscDHCPSubNetConf::IscDHCPSubNetConf()
{

}


IscDHCPSubNetConf::~IscDHCPSubNetConf()
{

}

string IscDHCPSubNetConf::generateConfig()
{
    return string("");
}

void IscDHCPSubNetConf::setServingIpRange(std::string startIp, std::string endIp) {
    this->setStartIp(startIp);
    this->setEndIp(endIp);
}
