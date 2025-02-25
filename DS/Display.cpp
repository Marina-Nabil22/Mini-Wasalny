#include "Display.h"
std::list<std::string> Display::DisplayGraphData(std::list<Town*>* Towns) {
    std::list<std::string> Data;
    if (!Towns)
        return Data;
    for (auto& Town : *Towns) {
        Data.push_back(Town->getName());
        Data.push_back("{");
        auto Destinations = Town->getDestinations();
        if (Destinations) {
            for (auto& Destination : *Destinations) {
                Data.push_back("    " + Destination.first->getName() + "    " + std::to_string(Destination.second));
            }
        }
        Data.push_back("}");
    }
    return Data;
}