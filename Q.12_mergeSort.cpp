#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&v, int low, int mid, int high){
    vector<int> output;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            output.push_back(v[left]);
            left++;
        }
        else{
            output.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        output.push_back(v[left]);
        left++;
    }
    while(right<=high){
        output.push_back(v[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        v[i] = output[i-low];
    }
}

void mergesort(vector<int>&v, int low, int high){
    if(low==high){
        return;
    }
    int mid = (low+high)/2;
    mergesort(v, low, mid);
    mergesort(v, mid+1, high);
    merge(v, low, mid, high);
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
    mergesort(res, 0, n-1);
    cout<<"Elements in vector after sorting "<<endl;
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}