#include<iostream>
using namespace std;

#define RED 0
#define BLACK 1

struct Node
{
    int val;
    bool color;
    Node * left;
    Node * right;
    Node * parent;
    Node(int);
    Node(int,Node *);
};

Node::Node(int val) {
    color = RED;
    this->val = val;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(int val,Node *parent) {
    color = RED;
    this->val = val;
    left = nullptr;
    right = nullptr;
    this->parent = parent;
}

void nilInit(Node * nil) {
    nil->color = BLACK;
    nil->left = nullptr;
    nil->right = nullptr;
    nil->parent = nullptr;
    nil->val = -1;
}

void InOrder(Node * root) {
    if(root == nullptr) {
        return;
    }

    InOrder(root->left);
    cout<<root->val;
    InOrder(root->right);
}


void LeftRotate(Node ** root) {
    Node * new_root = (*root)->right;
    Node * T = new_root->left;

    new_root->left = *root;
    (*root)->right = T;


}

int main() {
    Node * nil;
    nilInit(nil);

    Node * root;


    return 0;
}