
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;

    vector<int> values(n), weights(n);
    cout << "Enter value and weight of each item:\n";
    for(int i = 0; i < n; i++)
        cin >> values[i] >> weights[i];

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= capacity; w++) {
            if(weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][capacity] << endl;
    return 0;
}
