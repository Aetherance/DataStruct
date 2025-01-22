#include<iostream>
#include"stack.hpp"

using namespace std;

int main() {
    stack<int>s1;
    cout<<s1.empty();
    s1.push(10);
    s1.push(20);
    stack s2(s1);
    s1.push(30);

    while (!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    cout<<s1.size()<<endl;
    cout<<s1.empty()<<endl;

    while (!s2.empty())
    {
        cout<<s2.top()<<endl;
        s2.pop();
    }
    
    return 0;
}