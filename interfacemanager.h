#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include <string>
#include <vector>
#include <memory>

class InterfaceManager
{

public:
    InterfaceManager();
    std::shared_ptr<std::vector<std::string>> getWirelessInterfaces();
    std::shared_ptr<std::vector<std::string>> getAllInterfaces();
};

#endif // INTERFACEMANAGER_H
