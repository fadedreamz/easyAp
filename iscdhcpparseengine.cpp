#include "iscdhcpparseengine.h"
#include "iscdhcpsubnetconf.h"
#include "QDebug"
#include <QString>
#include <algorithm>
#include <sstream>

using namespace std;

IscDHCPParseEngine::IscDHCPParseEngine()
{

}


bool contains(std::string ws, char ch) {
    return find_if(ws.begin(), ws.end(), [ch](char m) {
        if (m == ch) return true;
        return false;
    }) != ws.end();
}


shared_ptr<SubNetConf> IscDHCPParseEngine::parseSubNetConf(std::string &conf)
{
    vector<string> items;
    std::string whitespaces(" \t\n\r;");
    string line;
    istringstream input;
    input.str(conf);
    // TODO:: excessive validation is not performed
    // need to verify it properly matches with the isc-dhcp-server construct
    while(getline(input, line)) {
        for(auto it = line.begin(); it != line.end(); it++) {
            if (!contains(whitespaces, *it)) {
                auto nit = it + 1;
                for(; nit != line.end(); nit++) {
                    if (contains(whitespaces, *nit))
                        break;
                }
                string segment = string(it, nit);
                if (segment == "#")
                    break;
                else if (segment != "" && segment != "{" && segment != "}")
                    items.push_back(segment);
                it = nit;
                if (it == line.end())
                    break;
            }
        }
    }

    shared_ptr<IscDHCPSubNetConf> config = shared_ptr<IscDHCPSubNetConf>(new IscDHCPSubNetConf());

    bool isValid = true;

    for(auto it = items.begin(); it != items.end(); it++) {
        qDebug() << QString((*it).c_str());
        if ((*it) == "subnet") {
            if (it + 1 != items.end()) {
                config->setNetwork(*(it + 1));
                it++;
            } else {
                isValid = false;
            }
        } else if ((*it) == "netmask") {
            if (it + 1 != items.end()) {
                config->setNetmask(*(it + 1));
                it++;
            } else {
                isValid = false;
            }
        } else if ((*it) == "range") {
            if (it + 1 != items.end() && it + 2 != items.end()) {
                config->setServingIpRange(*(it + 1), *(it + 2));
                it = it + 2;
            } else {
                isValid = false;
            }
        }
    }

    if (!isValid)
        return shared_ptr<SubNetConf>(nullptr);
    return dynamic_pointer_cast<SubNetConf>(config);
}


std::string IscDHCPParseEngine::getDriverName() {
    return string("isc-dhcp-server");
}
