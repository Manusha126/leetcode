#include <iostream>
using namespace std;

class MyLinkedList {
private:
    // Node structure
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head; // pointer to first node
    int size;   // number of nodes

public:
    // Constructor
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Get value at index
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->val;
    }

    // Add at head
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Add at tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
        size++;
    }

    // Add at index
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    // Delete at index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i)
                current = current->next;

            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }

        size--;
    }
};

// ------------------
// Test the class
// ------------------

int main() {
    MyLinkedList myLinkedList;

    myLinkedList.addAtHead(1);       // list: 1
    myLinkedList.addAtTail(3);       // list: 1 -> 3
    myLinkedList.addAtIndex(1, 2);   // list: 1 -> 2 -> 3

    cout << "Value at index 1: " << myLinkedList.get(1) << endl; // Output: 2

    myLinkedList.deleteAtIndex(1);   // list: 1 -> 3

    cout << "Value at index 1 after deletion: " << myLinkedList.get(1) << endl; // Output: 3

    return 0;
}