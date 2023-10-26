#include <iostream>
using namespace std;
//Insertion at the Beginning of an Array:
int main() {
    int arr[100];
    int n; 
    int element;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to insert at the beginning: ";
    cin >> element;
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    n++; 
    cout << "Array after insertion at the beginning: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//Deletion at the Beginning of an Array:
int main() {
    int arr[100];  
    int n;  
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; 
    cout << "Array after deletion at the beginning: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

