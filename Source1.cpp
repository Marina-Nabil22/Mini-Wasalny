#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<string>
using namespace std;

const int INF = 1e9; // infinity

 pair<int, int> pii; // pair of (distance, vertex)

unordered_map<string, int> vertexIndex; // map vertex labels to their index in the adjacency list
vector<vector<pii>> adj_list; // adjacency list representation of graph

void dijkstra(const string& start, const string& end, vector<int>& dist, vector<int>& prev) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap
    int source = vertexIndex[start];
    pq.push(make_pair(0, source)); // push source vertex with distance 0
    dist[source] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& edge : adj_list[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

vector<string> reconstructPath(const string& start, const string& end, const vector<int>& prev) {
    vector<string> path;
    int current = vertexIndex[end];
    while (current != -1) {
        path.push_back(to_string(current));
        current = prev[current];
    }
    reverse(path.begin(), path.end());
    for (auto& vertex : path) {
        vertex = vertexIndex[vertex];
    }
    return path;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    adj_list.resize(n);
    vertexIndex.reserve(n);

    for (int i = 0; i < n; i++) {
        string vertexLabel;
        cin >> vertexLabel;
        vertexIndex[vertexLabel] = i;
    }

    for (int i = 0; i < m; i++) {
        string u, v;
        int w; // edge from u to v with weight w
        cin >> u >> v >> w;
        adj_list[vertexIndex[u]].push_back(make_pair(vertexIndex[v], w));
        adj_list[vertexIndex[v]].push_back(make_pair(vertexIndex[u], w)); // for undirected graph
    }

    string start, end;
    cin >> start >> end;

    vector<int> dist(n, INF); // initialize distances to infinity
    vector<int> prev(n, -1); // initialize previous vertices

    dijkstra(start, end, dist, prev); // run Dijkstra's algorithm

    if (dist[vertexIndex[end]] == INF) {
        cout << "No path exists from " << start << " to " << end << endl;
    }
    else {
        cout << "Shortest distance from " << start << " to " << end << " is " << dist[vertexIndex[end]] << endl;
        vector<string> path = reconstructPath(start, end, prev);
        cout << "Path: ";
        for (const auto& vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}