#include <bits/stdc++.h>
using namespace std;

// Function to perform Prim's algorithm
vector<tuple<int, int, int>> prim(int V, vector<tuple<int, int, int>> &edges) {
   // Create an adjacency list
   vector<vector<pair<int, int>>> adj(V);
   for (const auto &[u, v, w] : edges) {
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
   }

   // Initialize key values to infinity and parent array
   vector<int> key(V, INT_MAX);
   vector<int> parent(V, -1);
   vector<bool> inMST(V, false);

   // Priority queue to pick the minimum weight edge
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   key[0] = 0;
   pq.emplace(0, 0);

   while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      inMST[u] = true;

      // Traverse all adjacent vertices of u
      for (const auto &[v, weight] : adj[u]) {
         if (!inMST[v] && weight < key[v]) {
            key[v] = weight;
            pq.emplace(key[v], v);
            parent[v] = u;
         }
      }
   }

   // Store the resulting MST
   vector<tuple<int, int, int>> mst;
   int total_weight = 0;
   for (int v = 1; v < V; ++v) {
      if (parent[v] != -1) {
         // Add edge to MST
         mst.emplace_back(parent[v], v, key[v]);
         total_weight += key[v];
      }
   }
   // Print the total weight of the MST
   cout << "Total weight of MST: " << total_weight << endl;
   return mst;
}

int main() {
   int V = 5; // Number of vertices
   vector<tuple<int, int, int>> edges = {
       {0, 1, 10},
       {0, 2, 6},
       {0, 3, 5},
       {1, 3, 15},
       {2, 3, 4}
   };

   // Call Prim's algorithm to get the MST
   vector<tuple<int, int, int>> mst = prim(V, edges);

   // Print the edges in the MST
   cout << "Edges in MST:" << endl;
   for (const auto &[u, v, w] : mst) {
      cout << "(" << u << ", " << v << ", " << w << ")" << endl;
   }
   return 0;
}