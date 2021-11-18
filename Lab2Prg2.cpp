#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int main(){
    stack<int> s;
    cout<<"Enter the string: ";
    char a[50];
    cin>>a;

    int n = strlen(a);
    
    int count = 0;

    for(int i=0; i<n; i++){
        s.push(a[i]);
    }
    for(int i=0; i<n; i++){
        if(a[i] == s.top()){
            count++;
            s.pop();
        }
    }

    if(count == n){
        cout<<"Palindrome"<<endl;
    } else{
        cout<<"Not a palindrome"<<endl;
    }    
    return 0;
}