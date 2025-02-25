#include "Bellmanford.h"

std::pair<std::list<std::string>, int> Bellmanford::GetShortestPath(std::string source, std::string destination, std::list<Town*>* Towns) {
    Town* start = nullptr;
    Town* end = nullptr;
    if (!Towns)
        return {};
    for (auto& Town : *Towns) {
        if (Town->getName() == source) {
            start = Town;
        }
        if (Town->getName() == destination) {
            end = Town;
        }
    }
    if (!start || !end) {
        return {};
    }
    std::unordered_map<std::string, std::pair<Town*, int>> table;
    for (auto& Town : *Towns) {
        table[Town->getName()] = { nullptr, INT_MAX };
    }
    table[source] = { nullptr, 0 };

    for (int i = 1; i <= Towns->size() - 1; i++) {
        for (auto& Town : *Towns) {
            auto Destinations = Town->getDestinations();
            if (!Destinations)
                continue;
            for (auto& Destination : *Destinations) {
                int totalCost = table[Destination.first->getName()].second;
                int curCost = table[Town->getName()].second + Destination.second;
                if (table[Town->getName()].second != INT_MAX && curCost < totalCost) {
                    table[Destination.first->getName()] = { Town, curCost };
                }
            }
        }
    }

    for (auto& Town : *Towns) {
        auto Destinations = Town->getDestinations();
        if (!Destinations)
            continue;
        for (auto& Destination : *Destinations) {
            int totalCost = table[Destination.first->getName()].second;
            int curCost = table[Town->getName()].second + Destination.second;
            if (table[Town->getName()].second != INT_MAX && curCost < totalCost) {
                return {};
            }
        }
    }

    if (!table[end->getName()].first)
        return {};
    std::pair<std::list<std::string>, int> ans;
    ans.second = table[end->getName()].second;
    ans.first.push_back(destination);
    while (ans.first.front() != source)
        ans.first.push_front(table[ans.first.front()].first->getName());
    return ans;
}
