
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

int main() {
    int n, capacity;
    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for(int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    sort(items.begin(), items.end(), compare);

    double totalValue = 0;
    for(auto item : items) {
        if(capacity == 0) break;
        if(item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += ((double)item.value / item.weight) * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum value: " << totalValue << endl;
    return 0;
}
