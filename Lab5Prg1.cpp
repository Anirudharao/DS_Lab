#include<iostream> 

using namespace std; 

class Node{ 

public: 

    int data; 

    Node* next; 

  

    Node(){ 

        data = 0; 

        next = NULL; 

    } 

  

    Node(int data){ 

        this->data = data; 

        this->next = NULL; 

    } 

}; 

  

class LinkedList{ 

    Node* head; 

  

public: 

  

    LinkedList(){ 

        head = NULL; 

    } 

  

    Node* insertEnd(int); 

    Node* insertBegin(int); 

    void insertBefore(int, int); 

    void insertAfter(int, int); 

    Node* deleteEle(int);

    void printList(Node*); 

}; 

  

Node* LinkedList::insertEnd(int data){ 

    Node* newNode = new Node(data); 

  

    if(head == NULL){ 

        head = newNode; 

        return head; 

    } 

  

    Node* temp = head; 

    while(temp->next != NULL){ 

        temp = temp->next; 

    } temp->next = newNode; 

    return head; 

} 

  

Node* LinkedList::insertBegin(int data){ 

    Node* temp = new Node(data); 

    temp->next = head; 

    head = temp; 

    return head;

} 

void LinkedList::insertBefore(int ele1, int ele2){ 

    Node* temp = new Node(ele2); 

    if(head == NULL){ 

        cout<<"List is empty"<<endl; 

        return; 

    } 

    else{ 

        Node* curr = head; 
        Node* prev = NULL;

        while(curr != NULL){ 

            if(curr->data == ele1){ 
                temp->next = curr; 
                if(prev != NULL){
                    prev->next = temp;
                } 
                return;
            }
            prev = curr;
            curr = curr->next;
        }

    } 

} 

void LinkedList::insertAfter(int ele, int elementToBeInserted){
    Node* temp = new Node(elementToBeInserted);
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        Node* curr = head;
        while(curr != NULL){
            if(curr->data == ele){
                temp->next = curr->next;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        }
    }
}  

Node* LinkedList::deleteEle(int ele){
    if(head == NULL){
        return  NULL;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL){
            if(curr->data == ele){
                prev->next = curr->next;
                delete curr;
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void LinkedList::printList(Node*){ 

     Node* temp = head; 

    if(head == NULL){ 

        cout<<"List is empty"<<endl; 

        return; 

    } 

        while(temp != NULL){ 

            cout<< temp->data<<" "; 

            temp = temp->next; 

        } 
        cout<<endl;
} 

  

int main(){ 
    
    LinkedList l1; 
    Node* head = NULL; 

    cout<<"Press 1 to insert an element at the beginning\n2 to insert an element at the end of the list"<<endl;
    cout<<"3 to insert an element before another element in the existing list\n4 to insert an element after another element in the existing list"<<endl;
    cout<<"5 to delete an element from the list\n6 to print the list\n7 to exit"<<endl;

    int opt;
    do{
        cout<<"Enter your option: ";
        cin>>opt;
        switch(opt){
        case 1:
            int ele;
            cout<<"Enter the element to be inserted: ";
            cin>>ele;
            l1.insertBegin(ele);
            break;
        case 2:
            //int ele;
            cout<<"Enter the element to be inserted: ";
            cin>>ele;
            l1.insertEnd(ele);
            break;
        case 3:
            int ele1, ele2;
            cout<<"Enter the element to be inserted: ";
            cin>>ele1;
            cout<<"Enter the element succeeding element: ";
            cin>>ele2;
            l1.insertBefore(ele2, ele1);
            break;
        case 4:
            
            cout<<"Enter the element to be inserted: ";
            cin>>ele1;
            cout<<"Enter the element preceeding element: ";
            cin>>ele2;
            l1.insertAfter(ele2, ele1);
            break;
        case 5:
            
            cout<<"Enter the element to be deleted: ";
            cin>>ele;
            l1.deleteEle(ele);
            break;
        case 6:
            l1.printList(head);
            break;
        default: 
            cout<<"Exit successful";
            break;
        }
    }    while(opt < 7);

    return 0; 

} 

 