#include "Graph.h"

Graph* Graph::S_instance = nullptr;

Graph::Graph() {
    this->Towns = nullptr;
}

Graph* Graph::Instance() {
    if (!S_instance)
        S_instance = new Graph();
    return S_instance;
}

void Graph::AddTown(std::string name, std::list<std::pair<Town*, int>>* Destinations) {
    if (!Towns) {
        Towns = new std::list<Town*>;
    }
    for (auto Town : *Towns) {
        if (Town->getName() == name) {
            return;
        }
    }
    Towns->push_back(new Town(std::move(name), Destinations));
}

std::list<Town*>* Graph::getTowns() {
    return this->Towns;
}

void Graph::UpdateEdge(std::string firstTown, std::string secondTown, int newCost) {
    if (!Towns)
        return;
    Town* town1 = nullptr;
    Town* town2 = nullptr;
    for (auto& Town : *Towns) {
        if (Town->getName() == firstTown) {
            town1 = Town;
        }
        else if (Town->getName() == secondTown) {
            town2 = Town;
        }
    }
    if (town1 && town2)
        town1->UpdateDestination(town2, newCost);
}

void Graph::DeleteEdge(std::string firstTown, std::string secondTown, int cost) {
    if (!Towns)
        return;
    Town* town1 = nullptr;
    Town* town2 = nullptr;
    for (auto& Town : *Towns) {
        if (Town->getName() == firstTown) {
            town1 = Town;
        }
        else if (Town->getName() == secondTown) {
            town2 = Town;
        }
    }
    if (town1 && town2)
        town1->RemoveDestination(town2, cost);
}

void Graph::AddEdge(std::string firstTown, std::string secondTown, int cost) {
    if (!Towns)
        return;
    Town* town1 = nullptr;
    Town* town2 = nullptr;
    for (auto& Town : *Towns) {
        if (Town->getName() == firstTown) {
            town1 = Town;
        }
        else if (Town->getName() == secondTown) {
            town2 = Town;
        }
    }
    if (town1 && town2)
        town1->AddDestination(town2, cost);
}

void Graph::RemoveTown(std::string name) {
    if (!Towns)
        return;
    Town* town = nullptr;
    for (auto it = Towns->begin(); it != Towns->end(); it++) {
        if ((*it)->getName() == name) {
            town = *it;
            Towns->erase(it);
            break;
        }
    }
    for (auto& Town : *Towns) {
        Town->RemoveMultipleDestinations(town);
    }
    delete town;
}

Graph::~Graph() {
    delete Towns;
}