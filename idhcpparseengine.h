#ifndef IDHCPPARSEENGINE_H
#define IDHCPPARSEENGINE_H

#include <memory>
#include "subnetconf.h"


class IDHCPParseEngine
{
public:
    IDHCPParseEngine();
    virtual ~IDHCPParseEngine();

    virtual std::string getDriverName() = 0;
    virtual std::shared_ptr<SubNetConf> parseSubNetConf(std::string & conf) = 0;

    static std::shared_ptr<IDHCPParseEngine> getEngineByDriverName(std::string driverName);
};

#endif // IDHCPPARSEENGINE_H
