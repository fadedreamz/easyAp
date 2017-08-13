#ifndef ISCDHCPPARSEENGINE_H
#define ISCDHCPPARSEENGINE_H

#include "idhcpparseengine.h"


class IscDHCPParseEngine : public IDHCPParseEngine
{
public:
    IscDHCPParseEngine();
    std::shared_ptr<SubNetConf> parseSubNetConf(std::string & conf);
    virtual std::string getDriverName();
};

#endif // ISCDHCPPARSEENGINE_H
