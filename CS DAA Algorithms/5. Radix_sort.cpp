#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int n = arr.size();
    
    int maxVal = *std::max_element(arr.begin(), arr.end());
    
    std::vector<int> count(maxVal + 1, 0);
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;}

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }
    
    std::vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    countingSort(arr);
    
    std::cout << "Sorted array:   ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    return 0;
}   
