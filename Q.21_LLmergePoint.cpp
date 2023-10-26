#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};
int getLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}
ListNode* findIntersection(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    int diff = abs(lenA - lenB);
    if (lenA > lenB) {
        for (int i = 0; i < diff; i++) {
            headA = headA->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            headB = headB->next;
        }
    }
    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
            return headA; 
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr; 
}

int main() {
    ListNode* commonNode = new ListNode(7);
    commonNode->next = new ListNode(8);
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = commonNode;
    ListNode* headB = new ListNode(3);
    headB->next = commonNode;
    cout << "Intersection Node: " << findIntersection(headA, headB)->val << endl;
    ListNode* current = headA;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    current = headB;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
