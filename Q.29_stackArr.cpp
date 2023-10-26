#include<iostream>
using namespace std;
//Stack implimetation through array
class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int n){
        capacity = n;
        arr = new int[n];
        top = -1;
    }
    //Function of stack
    void push(int data){
        if(top == capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop(){
        if (top==-1) {
            cout<<"Underflow"<<endl;
            return;
        }
        top--;
    }

    int topelement(){
        if(top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return arr[top];
    }

    bool isempty(){
        return top == -1;
    }

    int size(){
        return top+1;
    }

    bool isfull(){
        return top == capacity-1;
    }

};
int main(){
    stack s(5);
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.topelement()<<endl;
    s.push(4);
    s.push(5);
    cout<<s.topelement()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.isfull()<<endl;
    s.pop();
    cout<<s.topelement()<<endl;
    s.push(5);
    cout<<s.size()<<endl;
    s.push(10);
    return 0;
}