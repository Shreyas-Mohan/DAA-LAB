#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

// Function to solve the Travelling Salesman Problem using dynamic programming
int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();

    // Base case: all cities have been visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // Return the stored result if already computed
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n = 4; // Number of cities
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << "The minimum cost of the tour is " << tsp(1, 0, dist, dp) << endl;

    return 0;
}