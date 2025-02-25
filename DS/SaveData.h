#pragma once
#include "Graph.h"
#include <fstream>
class SaveData {
public:
    void Save(std::string id, std::list<Town*>* Towns);
};