#ifndef DHCPMANAGEMENT_H
#define DHCPMANAGEMENT_H

#include <string>
#include <vector>
#include <memory>

class DHCPManagement
{
protected:
    virtual std::shared_ptr<std::vector<std::string>> getSubNets() = 0;
public:
    DHCPManagement();
    virtual ~DHCPManagement();
    virtual void addNewSubNet(std::string network, std::string netmask, std::string startIp, std::string endIp) = 0;
};

#endif // DHCPMANAGEMENT_H
