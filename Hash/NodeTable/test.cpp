#include<iostream>
#include"hash"

using namespace std;

int main()
{
    HashTable h1(12);
    h1.insert(26);
    cout<<h1.find(26)<<endl;


    return 0;
}