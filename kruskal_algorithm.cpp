#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
   DisjointSet(int n)
   {
      parent.resize(n);
      rank.resize(n, 0);
      for (int i = 0; i < n; ++i)
      {
         parent[i] = i;
      }
   }
   int find(int v)
   {
      if (parent[v] != v)
      {
         parent[v] = find(parent[v]);
      }
      return parent[v];
   }
   void union_sets(int u, int v)
   {
      int root_u = find(u);
      int root_v = find(v);
      if (root_u != root_v)
      {
         if (rank[root_u] > rank[root_v])
         {
            parent[root_v] = root_u;
         }
         else if (rank[root_u] < rank[root_v])
         {
            parent[root_u] = root_v;
         }
         else
         {
            parent[root_v] = root_u;
            rank[root_u]++;
         }
      }
   }

private:
   vector<int> parent;
   vector<int> rank;
};
vector<tuple<int, int, int>> kruskal(int V, vector<tuple<int, int, int>> &
                                                edges)
{
   DisjointSet ds(V);
   vector<tuple<int, int, int>> mst;
   int total_weight = 0;
   sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
        { return get<2>(a) < get<2>(b); });

   for (const auto &[u, v, w] : edges)
   {
      if (ds.find(u) != ds.find(v))
      {
         ds.union_sets(u, v);
         mst.push_back({u, v, w});
         total_weight += w;
         if (mst.size() == V - 1)
         {
            break;
         }
      }
   }
   cout << "Total weight of MST: " << total_weight << endl;
   return mst;
}
int main()
{
   int V = 5;
   vector<tuple<int, int, int>> edges = {
       {0, 1, 10},
       {0, 2, 6},
       {0, 3, 5},
       {1, 3, 15},
       {2, 3, 4}};
   vector<tuple<int, int, int>> mst = kruskal(V, edges);
   cout << "Edges in MST:" << endl;
   for (const auto &[u, v, w] : mst)
   {
      cout << "(" << u << ", " << v << ", " << w << ")" << endl;
   }
   return 0;
}