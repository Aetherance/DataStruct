#include<iostream>
using namespace std;
#include<queue>


struct Node
{
    int val;
    Node * left;
    Node * right;
    Node(int);
};

Node::Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}

void PreOrderTraversal(Node * root) {
    if(root == nullptr) {
        return;
    }

    cout<<root->val<<endl;
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(Node*root) {
    if(root == nullptr) {
        return;
    }

    InOrderTraversal(root->left);
    cout<<root->val<<endl;
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node * root) {
    if(root == nullptr) {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->val<<endl;
}

void LevelOrderTraversal(Node * root) {
    queue<Node*>TreeQueue;
    TreeQueue.push(root);
    while (!TreeQueue.empty()) {
        Node * cur = TreeQueue.front();
        TreeQueue.pop();
        cout<<cur->val<<endl;
        if(cur->left) {
            TreeQueue.push(cur->left);
        }
        if(cur->right) {
            TreeQueue.push(cur->right);
        }
    }
}

int main() {

//      10
//     /  \
//    5   256
//   /    / \
//  123 345 250


    Node * root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(256);
    root->left->left = new Node(123);
    root->right->left = new Node(345);
    root->right->right = new Node(250);

    PreOrderTraversal(root);
    cout<<endl;
    InOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    LevelOrderTraversal(root);

    return 0;
}