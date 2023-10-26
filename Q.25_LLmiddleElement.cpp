#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) : data(value), next(nullptr) {}
};
ListNode* findMiddle(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         
        fast = fast->next->next;  
    }
    return slow;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original Linked List: ";
    printList(head);
    ListNode* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "Middle element: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
