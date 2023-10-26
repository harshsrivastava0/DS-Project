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

//Insertion at specific position
void insertspecific(node* head, int pos, int val){
    if(pos==0){
        inserthead(head, val);
        return;
    }

    node* k = new node(val);
    node* temp = head;
    int currentpos = 0;
    while(currentpos!=pos-1){
        temp = temp->next;
        currentpos++;
    }  
    k->next = temp->next;
    temp->next=k;
}

//delete at specific position
void deletespecific(node* &head, int pos){
    if(pos==0){
        return;
    }
    
    node* temp = head;
    int count = 0;
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }
    node* pre = temp->next;
    temp->next = temp->next->next;
    free(pre);
    
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
    insertspecific(head ,2,436789 );
    display(head);
    deletespecific(head, 1);
    display(head);
    return 0;
}