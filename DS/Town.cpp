#include "Town.h"

Town::Town(std::string name, std::list<std::pair<Town*, int>>* Destinations) {
    this->Name = name;
    this->Destinations = Destinations;
}

Town::Town(std::string name) {
    this->Name = name;
    Destinations = nullptr;
}

void Town::setName(std::string Name) {
    this->Name = Name;
}

std::string Town::getName() {
    return Name;
}

std::list<std::pair<Town*, int>>* Town::getDestinations() {
    return this->Destinations;
}

void Town::UpdateDestination(Town* town, int newCost) {
    if (!Destinations)
        return;
    for (auto& Destination : *Destinations) {
        if (Destination.first == town) {
            Destination.second = newCost;
            return;
        }
    }
}

void Town::AddDestination(Town* town, int cost) {
    if (!Destinations)
        Destinations = new std::list<std::pair<Town*, int>>;
    Destinations->emplace_back(town, cost);
}

void Town::RemoveDestination(Town* town, int cost) {
    if (!Destinations)
        return;

    for (auto it = Destinations->begin(); it != Destinations->end(); it++) {
        if (it->first == town && it->second == cost) {
            Destinations->erase(it);
            return;
        }
    }
}

void Town::RemoveMultipleDestinations(Town* town) {
    if (!Destinations)
        return;
    
    Destinations->remove_if([&](const std::pair<Town*, int>& Destination) {
        return Destination.first == town;
        });
}

Town::~Town() {
    delete Destinations;
}
