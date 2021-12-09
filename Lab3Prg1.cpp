#include<iostream>
using namespace std;

class queue{
    int a[10];
    int size;
    int front;
    int rear;

    queue(int n){
        size = n;
        front = -1;
        rear = -1;
    }

    void insert(int);
    int remove();
    void display();
};

void queue::insert(int ele){
    if(rear == size-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        a[++rear] = ele;
    }
}

int queue::remove(){
    if(rear == -1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        return a[++front];
    }
}

void queue::display(){
    if(rear == front){
        cout<<"Queue is empty"<<endl;
    }
    else{
        for(int i=front; i<=rear; i++){
        cout<<a[i]<<" ";
        }
    }
    
}

int main(){
    
    return 0;
}