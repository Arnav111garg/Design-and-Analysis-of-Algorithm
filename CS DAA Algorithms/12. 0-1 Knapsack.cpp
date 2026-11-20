#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    int weight;
    int value;
};

struct KnapsackResult {
    long long maxValue;
    vector<Item> selectedItems;
};

KnapsackResult solveKnapsack(int capacity, const vector<Item>& items) {
    int n = static_cast<int>(items.size());
    if (n == 0 || capacity <= 0) {
        return {0, {}};
    }

    // dp[i][w] = maximum value using items[0..i-1] with knapsack capacity w
    vector<vector<long long>> dp(n + 1, vector<long long>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        int wt = items[i - 1].weight;
        int val = items[i - 1].value;

        for (int w = 0; w <= capacity; w++) {
            // Exclude current item
            dp[i][w] = dp[i - 1][w];

            // Include current item if it fits
            if (wt <= w) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt] + val);
            }
        }
    }

    // Backtrack to recover the selected items (each item used at most once)
    vector<Item> chosen;
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(items[i - 1]);
            w -= items[i - 1].weight;
        }
    }

    reverse(chosen.begin(), chosen.end());
    return {dp[n][capacity], chosen};
}

int main() {
    int n, capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    if (n <= 0 || capacity < 0) {
        cout << "Invalid number of items or capacity.\n";
        return 0;
    }

    vector<Item> items(n);
    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cin >> items[i].weight >> items[i].value;
    }

    KnapsackResult res = solveKnapsack(capacity, items);

    cout << "\nMaximum Value: " << res.maxValue << "\n";
    cout << "Selected Items:\n";
    for (const auto& item : res.selectedItems) {
        cout << "  Item #" << item.id
             << " (Weight: " << item.weight
             << ", Value: " << item.value << ")\n";
    }

    return 0;
}