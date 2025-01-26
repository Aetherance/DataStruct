#include<iostream>
#include"hash"

using namespace std;

int main()
{
    hashtable h1(12);
    h1.Insert(10,25);
    h1.Insert(10,30);
    h1.Insert(10,40);
    h1.Insert(10,50);
    h1.Insert(20,20);
    cout<<h1.GetValue(10)<<endl;    
    cout<<h1.GetValue(20)<<endl;  
    // h1.Insert(5,256);
    cout<<h1[5]<<endl;
    
    return 0;
}
