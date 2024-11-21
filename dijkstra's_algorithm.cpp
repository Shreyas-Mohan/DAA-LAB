#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
void dijkstra(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& distances, vector<int>& predecessors) {
    int n = graph.size();
    distances.assign(n, INF);
    predecessors.assign(n, -1);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distances[u]) continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
}

void printShortestPath(int target, const vector<int>& predecessors) {
    stack<int> path;
    for (int at = target; at != -1; at = predecessors[at]) {
        path.push(at);
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    int n = 5; 
    vector<vector<pair<int, int>>> graph(n);

    // Example graph
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 6});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    int start = 0;
    vector<int> distances;
    vector<int> predecessors;

    dijkstra(start, graph, distances, predecessors);

    cout << "Shortest distances from vertex " << start << " to all other vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    int target = 3;
    cout << "Shortest path from vertex " << start << " to vertex " << target << ":" << endl;
    printShortestPath(target, predecessors);

    return 0;
}