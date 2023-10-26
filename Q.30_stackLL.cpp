#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class stack{
    node* head;
    int capacity;
    int current;
    public:
    stack(int n){
        capacity = n;
        current = 0;
        head = NULL;
    }

    bool isempty(){
        return head == NULL;
    }

    bool isfull(){
        return current = capacity;
    }

    void push(int data){
        if(current == capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        node* temp = new node(data);
        temp->next = head;
        head = temp;
        current++;
    }

    int pop(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        node* temp = head->next;
        head->next = NULL;
        node* del = head;
        int res = del->data;
        free(del);
        head = temp;
        return res;
    }

    int size(){
        return current;
    }

    int gettop(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }

        return head->data;
    }

};
int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.gettop()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.isfull()<<endl;
    // cout<<s.pop()<<endl;
    cout<<s.size()<<endl;

    return 0;
}