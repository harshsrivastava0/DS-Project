#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }
    void printList() {
        if (head == nullptr) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << " (back to head)" << endl;
    }
    void deleteNode(int value) {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == value) {
                if (current == head) {
                    // Deleting the head node
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtBeginning(3);
    cll.insertAtBeginning(2);
    cll.insertAtBeginning(1);
    cout << "Circular Linked List: ";
    cll.printList();
    cll.deleteNode(2);
    cout << "After deleting a node: ";
    cll.printList();
    return 0;
}
