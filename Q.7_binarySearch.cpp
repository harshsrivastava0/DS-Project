#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        switch (arr[mid] == key) {
            case true:
                return mid; 
            case false:
                if (arr[mid] < key) {
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
                break;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    switch (result) {
        case -1:
            cout << "Element not found in the array." << endl;
            break;
        default:
            cout << "Element found at index " << result << " in the array." << endl;
            break;
    }
    return 0;
}
