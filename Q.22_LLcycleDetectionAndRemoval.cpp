#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;  
        }
    }
    return false; 
}
void removeCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* start = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }
            slow = head;
            while (slow->next != start) {
                slow = slow->next;
            }
            slow->next = nullptr;
            return;
        }
    }
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    if (hasCycle(head)) {
        cout << "Cycle detected." << endl;
        removeCycle(head);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    cout << "Linked List: ";
    printList(head);
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
