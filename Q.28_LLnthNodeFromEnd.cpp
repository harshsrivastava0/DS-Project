#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};
ListNode* findNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n <= 0) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            return nullptr; 
        }
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
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
    int n = 3;
    ListNode* nthNode = findNthFromEnd(head, n);
    if (nthNode != nullptr) {
        cout << "Nth node from the end: " << nthNode->val << endl;
    } else {
        cout << "Nth node from the end not found." << endl;
    }
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
