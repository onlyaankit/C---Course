#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor 
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

//Traverse the linkedList 
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//Length of the linkedList 
int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

//insert to head of double linkedlist
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

//insert to tail of doubly linkedlist
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << "length is: " << getLength(head) << endl;
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 8);
    print(head);

    insertAtTail(tail, 25);
    return 0;
}