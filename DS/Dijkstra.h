#pragma once
#include "Town.h"
#include "IGetShortestPath.h"
#include <unordered_map>
#include <queue>

class Dijkstra : public IGetShortestPath {
public:
    std::pair<std::list<std::string>, int> GetShortestPath(std::string source, std::string destination, std::list<Town*>* Towns) override;
};
