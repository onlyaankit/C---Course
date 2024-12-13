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

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    cout << "length is: " << getLength(head) << endl;
    return 0;
}