#include <iostream>
using namespace std;
//Insertion at a User-Defined Location:
int main() {
    int arr[100]; 
    int n; 
    int pos, element;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the position to insert: ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position." << endl;
        return 0;
    }
    cout << "Enter the element to insert: ";
    cin >> element;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    n++; 
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//Deletion at a User-Defined Location:
int main() {
    int arr[100];  
    int n;  
    int pos;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the position to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position." << endl;
        return 0;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;  
    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


