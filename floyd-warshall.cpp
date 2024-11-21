#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

void floyd_warshall(vector<vector<int>>& dist, vector<vector<int>>& next) {
    int n = dist.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int u, int v, const vector<vector<int>>& next) {
    if (next[u][v] == -1) {
        cout << "No path" << endl;
        return;
    }
    vector<int> path;
    for (int at = u; at != v; at = next[at][v]) {
        if (at == -1) {
            cout << "No path" << endl;
            return;
        }
        path.push_back(at);
    }
    path.push_back(v);

    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << path[i];
    }
    cout << endl;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    vector<vector<int>> next(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] != INF) {
                next[i][j] = j;
            }
        }
    }

    floyd_warshall(dist, next);

    cout << "Matrix of shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    int u = 0, v = 3;
    cout << "Shortest path from vertex " << u << " to vertex " << v << ":" << endl;
    printPath(u, v, next);

    return 0;
}