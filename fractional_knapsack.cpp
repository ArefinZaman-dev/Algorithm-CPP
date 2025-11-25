#include <bits/stdc++.h>
using namespace std;

struct item {
    int weight;
    int profit;
    float p_w;
};

bool comp(item i1, item i2) {
    return i1.p_w > i2.p_w;   // Sort descending by profit/weight ratio
}

float fractional_knapsack(item item_list[], int len, int capacity) {
    // Step 1: find profit/weight ratio
    for (int i = 0; i < len; i++) {
        item_list[i].p_w = (float)item_list[i].profit / item_list[i].weight;
    }

    // Step 2: sort by p/w (descending)
    sort(item_list, item_list + len, comp);

    // Step 3: fill knapsack
    int current_capacity = capacity;
    float total_profit = 0;

    for (int i = 0; i < len; i++) {
        if (item_list[i].weight <= current_capacity) {
            total_profit += item_list[i].profit;
            current_capacity -= item_list[i].weight;
        }
        else {
            total_profit += (current_capacity * item_list[i].p_w);
            current_capacity = 0;
            break;
        }
    }

    return total_profit;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    item item_list[n];

    cout << "Enter weight & profit of each item (w p):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> item_list[i].weight >> item_list[i].profit;
        item_list[i].p_w = 0.0;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    float result = fractional_knapsack(item_list, n, capacity);

    cout << "Maximum profit = " << result << endl;

    return 0;
}
