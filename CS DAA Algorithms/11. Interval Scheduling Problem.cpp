#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    long long start;
    long long finish;
    long long weight;
};

struct Result {
    long long maxWeight;
    vector<Job> selectedJobs;
};

Result weightedIntervalScheduling(vector<Job> jobs) {
    int n = static_cast<int>(jobs.size());
    if (n == 0) {
        return {0, {}};
    }

    // 1. Sort intervals in non-decreasing order of finish time
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        if (a.finish != b.finish) return a.finish < b.finish;
        return a.start < b.start;
    });

    // Extract finish times so binary search can find the latest non-overlapping job
    vector<long long> finishTimes(n);
    for (int i = 0; i < n; i++) {
        finishTimes[i] = jobs[i].finish;
    }

    // p[i] = largest index j < i such that jobs[j].finish <= jobs[i].start (or -1 if none)
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(finishTimes.begin(), finishTimes.begin() + i, jobs[i].start);
        int idx = static_cast<int>(it - finishTimes.begin()) - 1;
        if (idx >= 0) {
            p[i] = idx;
        }
    }

    // 2. DP table: dp[i] = max weight achievable using a subset of jobs[0..i]
    vector<long long> dp(n, 0);
    dp[0] = jobs[0].weight;

    for (int i = 1; i < n; i++) {
        long long includeWeight = jobs[i].weight + (p[i] != -1 ? dp[p[i]] : 0);
        long long excludeWeight = dp[i - 1];
        dp[i] = max(includeWeight, excludeWeight);
    }

    // 3. Reconstruct the chosen intervals by walking backward from n - 1
    vector<Job> chosen;
    int i = n - 1;
    while (i >= 0) {
        long long includeWeight = jobs[i].weight + (p[i] != -1 ? dp[p[i]] : 0);
        long long excludeWeight = (i > 0) ? dp[i - 1] : 0;

        if (includeWeight >= excludeWeight) {
            chosen.push_back(jobs[i]);
            i = p[i];
        } else {
            i--;
        }
    }

    reverse(chosen.begin(), chosen.end());
    return {dp[n - 1], chosen};
}

int main() {
    int n;
    cout << "Enter number of intervals/jobs: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of intervals must be positive.\n";
        return 0;
    }

    vector<Job> jobs(n);
    cout << "Enter start time, finish time, and weight for each interval:\n";
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].weight;
    }

    Result res = weightedIntervalScheduling(jobs);

    cout << "\nMaximum Total Weight: " << res.maxWeight << "\n";
    cout << "Selected Non-Overlapping Intervals:\n";
    for (const auto& job : res.selectedJobs) {
        cout << "  Interval #" << job.id
             << " [" << job.start << ", " << job.finish << "]"
             << " (Weight: " << job.weight << ")\n";
    }

    return 0;
}