#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores weight and corresponding value
struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort items according to value/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get the maximum total value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    int currentWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Looping through all items
    for (auto& item : items) {
        // If adding the item won't overflow, add it completely
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            finalValue += item.value;
        }
        // If we can't add the current item, add fractional part of it
        else {
            int remain = W - currentWeight;
            finalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50; // Weight of knapsack
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, items) << endl;
    return 0;
}