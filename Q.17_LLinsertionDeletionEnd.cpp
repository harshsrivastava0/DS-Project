#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;

    node(int data){
        this->val = data;
        this->next = NULL;
    } 
}; 

//Insertion at End
void insertend(node* &head, int val){
    node* new_node = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = new_node; 
}

//delete at end
void deleteend(node* &head){
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}

//Transversing
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = new node(23);
    insertend(head,1);
    insertend(head,2);
    display(head);
    deleteend(head);
    display(head);
    return 0;
}