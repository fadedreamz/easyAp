#ifndef ISCDHCPSUBNETCONF_H
#define ISCDHCPSUBNETCONF_H

#include "subnetconf.h"
#include <string>

class IscDHCPSubNetConf : public SubNetConf
{
public:
    IscDHCPSubNetConf();
    virtual ~IscDHCPSubNetConf();
    virtual std::string generateConfig();

    void setServingIpRange(std::string startIp, std::string endIp);
};

#endif // ISCDHCPSUBNETCONF_H
