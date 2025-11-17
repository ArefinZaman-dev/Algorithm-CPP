#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);
    cout << "Enter start and finish time of each activity:\n";
    for(int i = 0; i < n; i++)
        cin >> activities[i].first >> activities[i].second;

    sort(activities.begin(), activities.end(), [](auto a, auto b) {
        return a.second < b.second;
    });

    cout << "Selected Activities Index (0-based): ";
    int lastEnd = -1;
    for(int i = 0; i < n; i++) {
        if(activities[i].first >= lastEnd) {
            cout << i << " ";
            lastEnd = activities[i].second;
        }
    }
    cout << endl;
    return 0;
}

