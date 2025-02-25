#pragma once
#include "Town.h"

class IGetShortestPath {
public:
    virtual std::pair<std::list<std::string>, int> GetShortestPath(std::string source, std::string destination, std::list<Town*>* Towns) = 0;
};