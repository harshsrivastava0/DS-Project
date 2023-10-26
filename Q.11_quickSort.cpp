#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void qs(vector<int>&arr, int low, int high){
    if(low<high){
        int pidx = partition(arr, low, high);
        qs(arr, low, pidx-1);
        qs(arr, pidx+1, high);
    }
}

int main(){
     int n;
    cout<<"Enter number of elements in vector ";
    cin>>n;
    vector<int>res;
    cout<<"Enter elements in vector "<<endl;
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        res.push_back(ele);
    }
    qs(res, 0, n-1);
    cout<<"Elements in vector after sorting "<<endl;
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}