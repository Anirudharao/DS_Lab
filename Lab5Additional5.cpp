#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* head){
    Node* curr = head;
    if(head == NULL) return;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    } while(curr != head);
}

Node* reverserList(Node* head){
    Node* curr = head;
    Node* prev = NULL;

    
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    
}

int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(40);
    Node* temp4 = new Node(50);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3; 
    temp3->next = temp4;
    temp4->next = NULL;

    head = reverserList(head);

    printList(head);

    return 0;
}
