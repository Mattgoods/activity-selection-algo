#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an activity with start and finish times
struct Activity {
    int start;
    int finish;
};

// Comparator to sort activities by their finish time
bool activityCompare(const Activity &a, const Activity &b) {
    return a.finish < b.finish;
}

// Greedy function to select the maximum number of non-overlapping activities
std::vector<Activity> selectActivities(const std::vector<Activity> &activities) {
    if (activities.empty()) return {};

    // Sort activities by finish time
    std::vector<Activity> sortedActivities = activities;
    std::sort(sortedActivities.begin(), sortedActivities.end(), activityCompare);

    std::vector<Activity> selected;
    selected.push_back(sortedActivities[0]);
    int lastFinish = sortedActivities[0].finish;

    for (size_t i = 1; i < sortedActivities.size(); ++i) {
        if (sortedActivities[i].start >= lastFinish) {
            selected.push_back(sortedActivities[i]);
            lastFinish = sortedActivities[i].finish;
        }
    }
    return selected;
}

// Utility function to read activities from standard input
std::vector<Activity> readActivities() {
    int n;
    std::cout << "Enter number of activities: ";
    std::cin >> n;
    std::vector<Activity> activities(n);
    std::cout << "Enter start and finish times (space separated):\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> activities[i].start >> activities[i].finish;
    }
    return activities;
}

// Utility function to print selected activities
void printActivities(const std::vector<Activity> &activities) {
    std::cout << "Selected activities:\n";
    for (const auto &act : activities) {
        std::cout << "[" << act.start << ", " << act.finish << "]\n";
    }
}

int main() {
    // Read activities from user
    std::vector<Activity> activities = readActivities();

    // Select maximum set of non-overlapping activities
    std::vector<Activity> selected = selectActivities(activities);

    // Output the result
    printActivities(selected);

    return 0;
}
