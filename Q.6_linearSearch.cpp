#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1;  
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = linearSearch(arr, n, key);
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
