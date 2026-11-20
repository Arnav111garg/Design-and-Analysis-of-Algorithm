#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<double>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }

    // Find minimum and maximum to support arbitrary ranges
    double minVal = *min_element(arr.begin(), arr.end());
    double maxVal = *max_element(arr.begin(), arr.end());

    // If all elements are identical, the array is already sorted
    if (minVal == maxVal) {
        return;
    }

    // Create n buckets
    vector<vector<double>> buckets(n);

    // Distribute elements into buckets based on normalized value
    for (int i = 0; i < n; i++) {
        int idx = static_cast<int>(((arr[i] - minVal) / (maxVal - minVal)) * (n - 1));
        buckets[idx].push_back(arr[i]);
    }

    // Sort individual buckets and concatenate back into arr
    int k = 0;
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (double val : buckets[i]) {
            arr[k++] = val;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 0;
    }

    vector<double> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr);

    cout << "Sorted array: ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}