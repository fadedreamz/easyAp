#ifndef SUBNETCONF_H
#define SUBNETCONF_H

#include <vector>
#include <string>
#include <memory>

class SubNetConf
{
protected:
    std::string network;
    std::string netmask;
    std::string startIP;
    std::string endIP;
    std::string gateway;
    std::vector<std::string> dns;
    std::string defaultLease;
    std::string maxLease;

    bool isIpAddr(std::string debugName, std::string & ip);
public:
    SubNetConf();
    virtual ~SubNetConf();

    std::string getNetwork();
    void setNetwork(std::string network);
    std::string getNetmask();
    void setNetmask(std::string netmask);
    std::string getStartIp();
    void setStartIp(std::string startIP);
    std::string getEndIp();
    void setEndIp(std::string endIp);

    static std::shared_ptr<SubNetConf> parseSubNetConfig(std::string config);

    virtual std::string generateConfig() = 0;
};

#endif // SUBNETCONF_H
