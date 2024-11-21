#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0-1 Knapsack problem
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 4; // Number of items
    int W = 7; // Capacity of knapsack
    vector<int> weights = {1, 3, 4, 5}; // Weights of items
    vector<int> values = {1, 4, 5, 7}; // Values of items

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}