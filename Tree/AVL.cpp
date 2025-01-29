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

int GetNodeHeight(Node * target) {
    if(target == nullptr) {
        return 0;
    }
    return target->height;
}

int GetHeight(Node * node) {
    if(node == nullptr) {
        return 0;
    }
    return node->height;
}

void UpdateHeight(Node * target) {
    target->height = max(GetHeight(target->left),GetHeight(target->right)) + 1;
}

int Balance(Node * target) {
    return GetHeight(target->left) - GetHeight(target->right);
}

void InOrder(Node* root) {
    if(root == nullptr) {
        return;
    }

    InOrder(root->left);
    cout<<root->val<<endl;
    InOrder(root->right);
}

void RightRotato(Node ** root) {
    if((*root)->left == nullptr) {
        perror("left is NULL");
        exit(1);
    } // 如果左子树为空，不能右旋

    Node * y = (*root)->left;
    Node * T2 = y->right;

    y->right = (*root);
    (*root)->left = T2;

    UpdateHeight(*root);
    UpdateHeight(y);

    (*root) = y;
}

void LeftRotato(Node ** root) {
    if((*root)->right == nullptr) {
        perror("right is NULL");
        exit(1);
    }

    Node * new_root = (*root)->right;
    Node * T = new_root->left;

    new_root->left = (*root);
    (*root)->right = T;

    UpdateHeight(*root);
    UpdateHeight(new_root);

    (*root) = new_root;
}

void Insert(Node** root,int val) {
    if(*root == nullptr) {
        *root = new Node(val);
        return;
    }

    if((*root)->val == val) {
        return;
    }

    if((*root)->val > val) {
        Insert(&(*root)->left,val);
    }
    else {
        Insert(&(*root)->right,val);
    }

    int balance = Balance(*root);
    if(balance == 2  && Balance((*root)->left) == 1) {
        RightRotato(root);
    }
    else if(balance == -2 && Balance((*root)->right) == -1) {
        LeftRotato(root);
    }
    else if(balance == 2 && Balance((*root)->left) == -1) {
        LeftRotato(&(*root)->left);
        RightRotato(root);
    }
    else if(balance == -2 && Balance((*root)->right) == 1) {
        RightRotato(&(*root)->right);
        LeftRotato(root);
    }
}

int main() {
    Node * root = nullptr;
    Insert(&root,10);
    Insert(&root,10);
    Insert(&root,5);
    Insert(&root,8);
    Insert(&root,25);
    Insert(&root,256);
    Insert(&root,999);
    


    InOrder(root);

    return 0;
}