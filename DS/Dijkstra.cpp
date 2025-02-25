#include "Dijkstra.h"

std::pair<std::list<std::string>, int> Dijkstra::GetShortestPath(std::string source, std::string destination, std::list<Town*>* Towns) {
    if (!Towns)
        return {};
    Town* start = nullptr;
    Town* end = nullptr;
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
    std::unordered_map<std::string, std::pair<Town*, int>> graph;
    // The First is The Parent and The Second is The Total Cost
    for (auto &Town : *Towns) {
        graph[Town->getName()] = { nullptr, INT_MAX };
    }
    graph[start->getName()] = {nullptr, 0};
    std::priority_queue<std::pair<int, Town*>, std::vector<std::pair<int, Town*>>, std::greater<> > pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        if (pq.top().second->getName() == destination)
            break;
        std::list<std::pair<Town*, int>>* Destinations = pq.top().second->getDestinations();
        int curCost = pq.top().first;
        Town* curTown = pq.top().second;
        pq.pop();
        if (!Destinations || graph[curTown->getName()].second < curCost)
            continue;
        for (auto &Destination : *Destinations) {
            int cost = Destination.second;
            Town* nextTown = Destination.first;
            if (cost + curCost < graph[nextTown->getName()].second) {
                graph[nextTown->getName()].second = cost + curCost;
                graph[nextTown->getName()].first = curTown;
                pq.push({ graph[nextTown->getName()].second, nextTown});
            }
        }
    }

    if (!graph[end->getName()].first)
        return {};
    std::pair<std::list<std::string>, int> ans;
    ans.second = graph[end->getName()].second;
    ans.first.push_back(destination);
    while (ans.first.front() != source)
        ans.first.push_front(graph[ans.first.front()].first->getName());
    return ans;
}
