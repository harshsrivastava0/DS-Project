#include<iostream>
using namespace std;
int main(){
    int arr[5];
    int n = 5;
    cout<<"Enter values for array :"<<endl;
    for (int i = 0; i < 5; i++)
    {
        int ele;
        cin>>ele;
        arr[ele];
    }
    cout<<"Elements before sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // INSERTION SORTING
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    cout<<"Elements after sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout<<endl;
    return 0;
}