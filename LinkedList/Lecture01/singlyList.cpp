#include <iostream>
using namespace std;

// Structure of a node in our linked list
class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Insert a new node in linked list at head
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

//insert at tail in single linkedlist
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

//insert at given position 
void insertAtPosition(Node* &head,Node* &tail, int position, int data){
    //insert at start of list
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

// Traverse the linked list
void print(Node* &head){
    Node* temp = head; // Fixing the case issue
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10); // Create a new node 
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // Head points to the new node
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 13);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head,tail, 5, 16);
    print(head);

    return 0; 
}