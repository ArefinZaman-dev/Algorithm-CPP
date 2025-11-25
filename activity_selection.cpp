#include <bits/stdc++.h>
using namespace std;

struct activity {
    int start;
    int finish;
};

bool comp(activity a1, activity a2) {
    return a1.finish < a2.finish;   // Sort by finishing time
}

int maximumActivity(activity arr[], int len) {
    sort(arr, arr + len, comp);     // Step 1: Sort

    int total_activity = 1;         // Select first activity
    int selected_index = 0;

    for (int j = 1; j < len; j++) {
        if (arr[j].start >= arr[selected_index].finish) {
            total_activity++;
            selected_index = j;
        }
    }

    return total_activity;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    activity arr[n];

    cout << "Enter start and finish time of each activity (s f):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    int result = maximumActivity(arr, n);

    cout << "Maximum number of activities = " << result << endl;

    return 0;
}
