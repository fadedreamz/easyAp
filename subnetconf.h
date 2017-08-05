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
public:
    SubNetConf();
    virtual ~SubNetConf();

    std::string getNetwork();
    void setNetwork(std::string network);
    std::string getNetmask();
    void setNetmask(std::string netmask);

    static std::shared_ptr<SubNetConf> parseSubNetConfig(std::string config);

    virtual std::string generateConfig() = 0;
};

#endif // SUBNETCONF_H
