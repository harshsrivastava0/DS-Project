#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    void printBackward() {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
    void deleteNode(int value) {
        if (head == nullptr) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(1);
    dll.insertAtEnd(3);
    dll.insertAtBeginning(2);
    cout << "Doubly Linked List (Forward): ";
    dll.printForward();
    cout << "Doubly Linked List (Backward): ";
    dll.printBackward();
    dll.deleteNode(3);
    cout << "After deleting a node: ";
    dll.printForward();
    return 0;
}
