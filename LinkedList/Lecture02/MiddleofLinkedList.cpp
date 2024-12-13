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

// Find the middle node of the linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move slow by one step and fast by two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow will point to the middle node
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original Linked List: ";
    print(head);

    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle Node: " << middle->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}
