#include "iscdhcpparseengine.h"
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

    for(auto it = items.begin(); it != items.end(); it++) {
        qDebug() << QString((*it).c_str());
    }

    return shared_ptr<SubNetConf>(nullptr);
}
