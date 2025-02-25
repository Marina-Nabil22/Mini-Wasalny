#pragma once
#include "Town.h"
#include "IGetShortestPath.h"
#include <set>
#include <unordered_map>

class Bellmanford : public IGetShortestPath
{
public:
	std::pair<std::list<std::string>, int> GetShortestPath(std::string source, std::string destination, std::list<Town*>* Towns) override;
};

