#include<iostream>
using namespace std;

enum Color {
    RED,
    BLACK
};

struct Node {
    int data;
    bool color;
    Node *left,*right,*parent;
    Node(int data);
};

Node::Node(int data) {
    this->data = data;
    this->color = RED;
    this->left = this->parent = this->right = nullptr;    
}

class RBTree 
{
public:
    RBTree();
    ~RBTree();
    Node * get();
    void InOrder(Node *);
    void Insert(Node *,int);
    void InsertFix();

private:
    Node * root;
    Node * nil;
};

RBTree::RBTree(){
    nil = new Node(-1);
    nil->color = BLACK;
    nil->left = nullptr;
    nil->parent = nullptr;
    nil->right = nullptr;
    root = nil;
}

RBTree::~RBTree(){
    delete nil;
}

Node *RBTree::get() {
    return root;
}

void RBTree::InOrder(Node * node) {
    if(node == nil) {
        return;
    }
    InOrder(node->left);
    cout<<node->data<<endl;
    InOrder(node->right);
}

void RBTree::Insert(Node * node,int val) {
    if(val == node->data) {
        return;
    } else if(val > node->data) {
        Insert(node->right,val);
    } else if(val < node->data) {
        Insert(node->left,val);
    }
    

}

void RBTree::InsertFix() {

}

int main() {
    RBTree tree;
    Node * root = tree.get();


    tree.InOrder(root);
    return 0;
}