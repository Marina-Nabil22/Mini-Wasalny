#pragma once
#include "Town.h"

class Graph {
private:
    std::list<Town*>* Towns;
    
    static Graph* S_instance;

    Graph();

public:
    
    void AddTown(std::string name, std::list<std::pair<Town*, int>>* Destinations = nullptr);
    
    std::list<Town*>* getTowns();

    void RemoveTown(std::string name);

    void AddEdge(std::string firstTown, std::string secondTown, int cost);

    void UpdateEdge(std::string firstTown, std::string secondTown, int newCost);

    void DeleteEdge(std::string firstTown, std::string secondTown, int cost);

    static Graph* Instance();

    ~Graph();
};
