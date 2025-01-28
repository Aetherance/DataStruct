#include<iostream>
using namespace std;

struct Node
{
    int val;
    int height;
    Node *left;
    Node *right;

    Node(int);
};

Node::Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}

void InOrder(Node* root) {
    if(root == nullptr) {
        return;
    }

    cout<<root->val<<endl;
    InOrder(root->left);
    InOrder(root->right);
}

void Insert(Node* root,int val) {
    
}

int main() {
    Node * root = new Node(10);


    InOrder(root);

    return 0;
}