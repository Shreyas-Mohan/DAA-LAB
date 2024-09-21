#include <bits/stdc++.h>

using namespace std;

// Structure for an activity which stores start and finish time
struct Activity {
    int start, finish;

    // Constructor
    Activity(int start, int finish) : start(start), finish(finish) {}
};

// Comparison function to sort activities according to their finish time
bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to perform activity selection
void activitySelection(vector<Activity>& activities) {
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected activities are: " << endl;

    // The first activity always gets selected
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;

    // Consider the rest of the activities
    for (int j = 1; j < activities.size(); j++) {
        // If this activity has a start time greater than or equal to the finish time of the previously selected activity, select it
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main() {
    vector<Activity> activities = { {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9} };

    activitySelection(activities);

    return 0;
}