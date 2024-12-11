#include <iostream>
using namespace std;

// Structure of a node in our linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        cout << "Memory is free for node with data " << this->data << endl;
    }
};

// Insert a new node at the head
void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert a new node at the tail
void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Insert a node at a specific position
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds! Inserting at the tail." << endl;
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if (nodeToInsert->next == NULL) {
        tail = nodeToInsert;
    }
}

// Delete a node at a specific position
void deleteNode(int position, Node*& head, Node*& tail) {
    if (position <= 0 || head == NULL) {
        cout << "Invalid position or empty list!" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;  // Update tail if list becomes empty
        }
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while (count < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    prev->next = curr->next;

    if (curr->next == NULL) {
        tail = prev;  // Update tail if the last node is deleted
    }

    delete curr;
}

// Calculate the length of the linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Traverse and print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create the first node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    // Test insertion at tail
    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 13);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    // Test insertion at a specific position
    insertAtPosition(head, tail, 5, 16);
    print(head);

    // Test deletion
    deleteNode(1, head, tail);
    print(head);

    deleteNode(3, head, tail);
    print(head);

    deleteNode(10, head, tail);  // Test invalid position
    print(head);

    // Free all nodes
    while (head != NULL) {
        deleteNode(1, head, tail);
    }

    return 0;
}
