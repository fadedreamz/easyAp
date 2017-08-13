#include "interfacemanager.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <algorithm>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <QDebug>
using namespace std;

#define MAX_HOSTNAME 1024

InterfaceManager::InterfaceManager()
{

}


std::shared_ptr<std::vector<std::string>> InterfaceManager::getAllInterfaces() {
    shared_ptr<vector<string>> interfaceList = shared_ptr<vector<string>>(new vector<string>());
    struct ifaddrs * ifaddr, *ifa;
    char hostname[MAX_HOSTNAME];
    if (getifaddrs(&ifaddr) == -1)
        return interfaceList;
    for(ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;
        bool newEntry = true;
        for(auto it = interfaceList->begin(); it != interfaceList->end(); it++) {
            if (*it == string(ifa->ifa_name)) {
                newEntry = false;
                break;
            }
        }
        if (newEntry && string(ifa->ifa_name) != string("lo"))
            interfaceList->push_back(string(ifa->ifa_name));
    }

    return interfaceList;
}


std::shared_ptr<std::vector<std::string>> InterfaceManager::getWirelessInterfaces() {
    auto allIfList = this->getAllInterfaces();
    vector<string>::iterator it;
    while(allIfList->end() != (it = std::find_if(allIfList->begin(), allIfList->end(), [](string ifname) {
                         struct iwreq pwrq;
                         memset(&pwrq, 0, sizeof(pwrq));
                         strncpy(pwrq.ifr_name, ifname.c_str(), IFNAMSIZ);
                         int sock = socket(AF_INET, SOCK_STREAM, 0);
                         if (sock == -1) return true;
                         if (ioctl(sock, SIOCGIWNAME, &pwrq) == -1) return true;
                         close(sock);
                         qDebug() << ifname.c_str() << " " << pwrq.u.name;
                         return false;
                     }))) {
        allIfList->erase(it);
    }
    return allIfList;
}
