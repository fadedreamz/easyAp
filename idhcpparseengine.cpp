#include "idhcpparseengine.h"

#include "iscdhcpparseengine.h"

using namespace std;

IDHCPParseEngine::IDHCPParseEngine()
{

}

IDHCPParseEngine::~IDHCPParseEngine()
{

}

std::shared_ptr<IDHCPParseEngine> IDHCPParseEngine::getEngineByDriverName(std::string driverName) {
    if (driverName == "isc-dhcp-server")
        return shared_ptr<IDHCPParseEngine>(new IscDHCPParseEngine());
    return shared_ptr<IDHCPParseEngine>(nullptr);
}
