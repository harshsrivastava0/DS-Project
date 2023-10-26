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

class queue{
    node* head;
    node* tail;
    int size;
    public:
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void enqueue(int x){
        node* temp = new node(x);
        if(head==NULL){
            head = tail = temp;
        }
        else{
            tail->next=temp;
            tail = temp;
        }
        size++;
        
    }

    void dequeue(){
        if(head == NULL){
            return;
        }
        node* old = head;
        node* newone = head->next;
        head = newone;
        if(head == NULL){
            tail = NULL;
            old->next = NULL;
            free(old);
            size--;
        }
    }
    
    int getsize(){
        return this->size;
    }

    bool isempty(){
        return head == NULL;
    }

    int front(){
        if(head == NULL)return -1;
        return head->data;
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    while(!q.isempty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }

    return 0;
}