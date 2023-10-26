#include <iostream>
using namespace std;
//Insertion at the End of an Array:
int main() {
    int arr[100];  
    int n; 
    int element;
    cout << "Enter the number of elements in the array: ";
    cin >> n; 
    if(n>100){
        cout<<"OVERFLOW-you cannot add more elements to array"<<endl;
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to insert at the end: ";
    cin >> element;
    arr[n] = element;
    n++; 
    cout << "Array after insertion at the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//Deletion at the End of an Array:
int main() {
    int arr[100];  
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n <= 0) {
        cout << "UNDERFLOW-you cannot delete element from empty array" << endl;
        return 0;
    }
    n--;
    cout << "Array after deletion at the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


