#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>arr = {56,91,62,31,13,48,20,4,81,17,34,58,61,6,53,57,44,75,83,69};

int search(int begin,int end,int num) {
    int mid = (begin + end)/2;
    if(arr[mid] == num) {
        return mid;
    }
    else if(arr[mid]>num) {
        search(begin,mid,num);
    }
    else{
        search(mid+1,end,num);
    }
    return -1;
}

int main() {
    sort(arr.begin(),arr.end());
    cout<<search(0,arr.size()-1,17);


    return 0;
}