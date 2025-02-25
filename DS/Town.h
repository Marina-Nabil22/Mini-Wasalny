#pragma once
#include <string>
#include <list>

class Town {
private:
    std::string Name;
    std::list<std::pair<Town*, int>>* Destinations;
public:
    Town(std::string name, std::list<std::pair<Town*, int>>* Destinations);

    explicit Town(std::string name);

    void setName(std::string Name);

    std::string getName();

    std::list<std::pair<Town*, int>>* getDestinations();

    void UpdateDestination(Town* town, int newCost);

    void AddDestination(Town* town, int cost);

    void RemoveDestination(Town* town, int cost);

    void RemoveMultipleDestinations(Town* town);

    ~Town();

};

