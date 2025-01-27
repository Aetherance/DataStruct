#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int);
};

Node::Node(int val) {
    this->val = val;
    this->right = nullptr;
    this->left = nullptr;
}

void BST_Insert(Node **root,int val) {
    if(*root == nullptr) {
        *root = new Node(val);
        return;
    }

    if(val == (*root)->val) {
        return;
    }

    if(val<(*root)->val) {
        BST_Insert(&(*root)->left,val);
    }

    if(val>(*root)->val) {
        BST_Insert(&(*root)->right,val);
    }
}

void BST_Print(Node *root) {
    if(root == nullptr) {
        return;
    }

    BST_Print(root->left);
    cout<<root->val<<endl;
    BST_Print(root->right);
}

int BST_search(Node *root,int val) {
    if(root == nullptr) {
        return -1;
    }

    if(val == root->val) {
        return val;
    }

    if(val < root->val) {
        return BST_search(root->left,val);
    }

    if(val > root->val) {
        return BST_search(root->right,val);
    }
    return -1;
}

Node * BST_FindLeftMax(Node * root) {
    Node * left_max = root->left;
    while (left_max&&left_max->right) {
        left_max = left_max->right;
    }
    return left_max;
}

void BST_Delete(Node **root,int val) {
    if(*root==nullptr) {
        return;
    }
    if(val<(*root)->val) {
        BST_Delete(&(*root)->left,val);
    }
    if(val>(*root)->val) {
        BST_Delete(&(*root)->right,val);
    }

    Node * temp = *root;
    if(!(*root)->left&&!(*root)->right) {
        *root = nullptr;
        delete temp;
    }
    else if((*root)->left&&!(*root)->right) {
        *root = (*root)->left;
        delete temp;    
    }
    else if(!(*root)->left&&(*root)->right) {
        *root = (*root)->right;
        delete temp;
    }
    else {
        (*root)->val = BST_FindLeftMax(*root)->val;
        BST_Delete(&temp,(*root)->val);
    }
}

int main() {

    Node * root = nullptr;
    BST_Insert(&root,10);
    BST_Insert(&root,20);
    BST_Insert(&root,6);
    BST_Insert(&root,0);
    
    BST_Print(root);

    cout<<BST_search(root,256)<<endl;
    cout<<BST_search(root,0)<<endl;
    BST_Delete(&root,0);
    cout<<BST_search(root,0)<<endl;


    return 0;
}