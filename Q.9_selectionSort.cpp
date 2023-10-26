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
    // SELECTION SORTING
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int minidx = -1;
        for (int j = i; j <= n - 1; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minidx = j;
            }
        }
        int temp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = temp;
    }
    cout<<"Elements after sorting"<<endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout<<endl;
    return 0;
}