#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ngr(n, -1); 

    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ngr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ngr;
}

vector<int> nextGreaterLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ngl(n, -1); 
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ngl[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ngl;
}

vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nsl(n, -1); 
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            nsl[i] = arr[st.top()];
        }
        st.push(i);
    }
    return nsl;
}


vector<int> nextSmallerRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nsr(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            nsr[i] = arr[st.top()];
        }
        st.push(i);
    }
    return nsr;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ngr = nextGreaterRight(arr);
    vector<int> ngl = nextGreaterLeft(arr);
    vector<int> nsl = nearestSmallerLeft(arr);
    vector<int> nsr = nextSmallerRight(arr);
    cout << "Next Greater Element to the Right: ";
    for (int val : ngr) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Next Greater Element to the Left: ";
    for (int val : ngl) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Nearest Smaller Element to the Left: ";
    for (int val : nsl) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Next Smaller Element to the Right: ";
    for (int val : nsr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
