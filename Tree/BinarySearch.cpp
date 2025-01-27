#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>arr = {56,91,62,31,13,48,20,4,81,17,34,58,61,6,53,57,44,75,83,69};

int search(int begin,int end,int num) {
    if(begin > end) {
        return -1;
    }
    int mid = (begin + end)/2;
    if(arr[mid] == num) {
        return mid;
    }
    else if(arr[mid]>num) {
        return search(begin,mid-1,num);
    }
    else {
        return search(mid+1,end,num);
    }
}

int main() {
    sort(arr.begin(),arr.end());
    for(auto i : arr) {
        cout<<i<<endl;
    }
    cout<<search(0,arr.size()-1,17)<<endl;
    cout<<search(0,arr.size()-1,17)<<endl;
    cout<<search(0,arr.size()-1,4)<<endl;
    cout<<search(0,arr.size()-1,70)<<endl;
    cout<<search(0,arr.size()-1,0)<<endl;
    cout<<search(0,arr.size()-1,58)<<endl;

    return 0;
}