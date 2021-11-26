#include<iostream> 
#include<stack> 

using namespace std; 

int main() { 
    string s; 
    cout<<"Enter the expression: "; 
    cin>>s; 
    stack<char> st; 
    for(int i=0;i<s.length();i++) { 

        if(s[i]=='(') { 
            st.push(s[i]); 
        } 

        else if(s[i]==')') { 
            if(st.empty()) { 
            cout<<"Not balanced"<<endl; 
            return 0; 
            } 
            else { 
            st.pop(); 
            } 

        } 
    } 

    if(st.empty()) { 
        cout<<"Balanced"<<endl; 
    } 
    else { 
        cout<<"Not balanced"<<endl; 
    } 
    return 0; 

} 