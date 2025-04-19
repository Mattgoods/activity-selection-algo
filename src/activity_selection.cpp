#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <sys/resource.h>

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

// Function to generate random activities
typedef std::pair<int, int> IntPair;
std::vector<Activity> generateRandomActivities(int n, int maxTime = 1000000) {
    std::vector<Activity> activities(n);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxTime);
    for (int i = 0; i < n; ++i) {
        int start = dist(rng);
        int finish = dist(rng);
        if (start > finish) std::swap(start, finish);
        if (start == finish) finish += 1;
        activities[i] = {start, finish};
    }
    return activities;
}

// Function to get peak memory usage (in kilobytes)
long getPeakMemoryKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

// Utility function to print selected activities
void printActivities(const std::vector<Activity> &activities) {
    std::cout << "Selected activities:\n";
    for (const auto &act : activities) {
        std::cout << "[" << act.start << ", " << act.finish << "]\n";
    }
}

int main(int argc, char* argv[]) {
    int n = 0;
    bool useRandom = false;
    if (argc == 3 && std::string(argv[1]) == "--random") {
        n = std::stoi(argv[2]);
        useRandom = true;
    }
    std::vector<Activity> activities;
    if (useRandom) {
        activities = generateRandomActivities(n);
    } else {
        activities = readActivities();
    }
    auto memBefore = getPeakMemoryKB();
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Activity> selected = selectActivities(activities);
    auto end = std::chrono::high_resolution_clock::now();
    auto memAfter = getPeakMemoryKB();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    printActivities(selected);
    std::cout << "\nExperimental Analysis Results:\n";
    std::cout << "Input size: " << activities.size() << "\n";
    std::cout << "Running time (ms): " << elapsed.count() << "\n";
    std::cout << "Peak memory usage (KB): " << memAfter << "\n";
    return 0;
}
