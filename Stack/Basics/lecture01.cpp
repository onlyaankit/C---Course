#include <bits/stdc++.h>
using namespace std;

int main(){
    //creation of stack 
    stack<int>s;

    //push elements into stack
    s.push(1);
    s.push(2);

    //pop element from stack
    s.pop();
   
    cout<< s.top()<< endl;

    //check stack is empty or not 
    if(s.empty()){
        cout<< "stack is empty"<< endl;
    }else{
        cout<< "stack is not empty"<< endl;
    }
    return 0;
}