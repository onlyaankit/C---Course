#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Traverse and print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse a linked list
void reverseList(Node*& head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move prev one step ahead
        curr = next;        // Move curr one step ahead
    }

    head = prev;  // Update the head to the new front
}

// Get the length of the linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original Linked List: ";
    print(head);

    reverseList(head);

    cout << "Reversed Linked List: ";
    print(head);

    cout << "Length of the Linked List: " << getLength(head) << endl;

    return 0;
}
