#ifndef IDHCPPARSEENGINE_H
#define IDHCPPARSEENGINE_H

#include <memory>
#include "subnetconf.h"


class IDHCPParseEngine
{
public:
    IDHCPParseEngine();
    virtual ~IDHCPParseEngine();

    virtual std::shared_ptr<SubNetConf> parseSubNetConf(std::string & conf) = 0;

};

#endif // IDHCPPARSEENGINE_H
