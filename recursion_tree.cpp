#include <iostream>
#include <queue>
using namespace std;
const int MAX_NODES = 100;
struct Node
{
   int size;
   int level;
};
int main()
{
   int n = 100;
   int a, b, depth;
   cout << "Enter the number of subproblems (a): ";
   cin >> a;
   cout << "Enter the division factor (b): ";
   cin >> b;
   cout << "Enter the maximum depth of the recursion tree: ";
   cin >> depth;
   queue<Node> q;
   q.push({n, 0});
   while (!q.empty())
   {
      Node current = q.front();
      q.pop();
      for (int i = 0; i < current.level; ++i)
      {
         cout << " ";
      }
      cout << "Level " << current.level << ": Size " << current.size << endl;
      if (current.level < depth)
      {
         q.push({current.size / b, current.level + 1});
         q.push({current.size / b, current.level + 1});
      }
   }
   return 0;
}