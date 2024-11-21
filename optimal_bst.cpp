#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of frequencies from i to j
int sum(const vector<int>& freq, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to find the optimal cost of the BST
int optimalSearchTree(const vector<int>& keys, const vector<int>& freq, int n) {
    vector<vector<int>> cost(n, vector<int>(n, 0));

    // Cost for a single key
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // L is the chain length
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> keys(n);
    vector<int> freq(n);

    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n) << endl;

    return 0;
}