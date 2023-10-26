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

//Insertion at begining
void inserthead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

//delete at start
void deletestart(node* &head){
    node* temp = head;
    head = temp->next;
    free(temp); 
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
    inserthead(head, 10);
    display(head);
    inserthead(head,1);
    display(head);
    deletestart(head);
    display(head);
    return 0;
}