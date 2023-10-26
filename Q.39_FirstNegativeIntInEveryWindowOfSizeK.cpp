#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void findFirstNegativeInWindow(const vector<int>& arr, int k) {
    int n = arr.size();

    if (n == 0 || k <= 0) {
        return;
    }

    deque<int> negativeIndices;

    // Process the first window separately
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negativeIndices.push_back(i);
        }
    }

    // Process the remaining windows
    for (int i = k; i < n; i++) {
        // Print the first negative element in the previous window
        if (!negativeIndices.empty()) {
            cout << arr[negativeIndices.front()] << " ";
        } else {
            cout << "0 "; // No negative element in the previous window
        }

        // Remove indices that are out of the current window
        while (!negativeIndices.empty() && negativeIndices.front() <= i - k) {
            negativeIndices.pop_front();
        }

        // Add the index of the current element to the deque if it's negative
        if (arr[i] < 0) {
            negativeIndices.push_back(i);
        }
    }

    // Print the first negative element in the last window
    if (!negativeIndices.empty()) {
        cout << arr[negativeIndices.front()] << " ";
    } else {
        cout << "0 "; // No negative element in the last window
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    findFirstNegativeInWindow(arr, k);

    return 0;
}
