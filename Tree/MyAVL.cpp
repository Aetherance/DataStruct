#include<iostream>
using namespace std;

struct Node
{
    int val;
    int height;
    Node * left;
    Node * right;
    Node(int);
};

Node::Node(int val) {
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
    this->val = val;
}

int getHeight(Node * target) {
    if(target == nullptr) {
        return 0;
    }
    return target->height;
}

void updateHeight(Node * target) {
    target->height = max(getHeight(target->left),getHeight(target->right)) + 1;
}

int getBalance(Node * target) {
    return getHeight(target->left) - getHeight(target->right);
}

void InOrder(Node * root) {
    if(root == nullptr) {
        return ;
    }

    InOrder(root->left);
    cout<<root->val<<endl;
    InOrder(root->right);
}

void LeftRotate(Node ** root) {
    Node * new_root = (*root)->right;
    Node * T = new_root->left;

    new_root->left = *root;
    (*root)->right = T;

    updateHeight(*root);
    updateHeight(new_root);

    *root = new_root;    
}

void RightRotate(Node ** root) {
    Node * new_root = (*root)->left;
    Node * T = new_root->right;

    new_root->right = (*root);
    (*root)->left = T;

    updateHeight(*root);
    updateHeight(new_root);

    *root = new_root;
}

void Insert(Node ** root,int val) {
    if(*root == nullptr) {
        *root = new Node(val);
        return ;
    }

    if(val == (*root)->val) {
        return;
    }

    if(val<(*root)->val) {
        Insert(&(*root)->left,val);
    }
    else if(val>(*root)->val) {
        Insert(&(*root)->right,val);
    }
    
    updateHeight(*root);

    int balance = getBalance(*root);

    if(balance == 2) {
        if(getBalance((*root)->left) == 1) {
            RightRotate(root);
        } 
        else if(getBalance((*root)->left) == -1) {
            LeftRotate(&(*root)->left);
            RightRotate(&(*root));
        }
    }
    else if(balance == -2) {
        if(getBalance((*root)->right) == 1) {
            RightRotate(&(*root)->right);
            LeftRotate(root);
        }
        else if(getBalance((*root)->right) == -1) {
            LeftRotate(root);
        }
    }
}

Node * findLeftMax(Node * root) {
    Node * max = root->left;
    while (max && max->right) {
        max = max->right;
    }
    return max;
}

void remove(Node ** root,int val) {
    if(*root == nullptr) {
        return;
    }

    if(val<(*root)->val) {
        remove(&(*root)->left,val); 
    }
    else if(val > (*root)->val) {
        remove(&(*root)->right,val);
    }
    else {
        Node * temp = *root;
        if(!(*root)->left && !(*root)->right) {
            delete *root;
            *root = nullptr;
        }
        else if((*root)->left && !(*root)->right) {
            *root = (*root)->left;
            delete temp;
        }
        else if((*root)->right && !(*root)->left) {
            *root = (*root)->right;
            delete temp;
        }
        else {
            Node * leftMax = findLeftMax(*root);
            (*root)->val = leftMax->val;
            remove(&(*root)->left,leftMax->val);
        }
    }
    
    if(*root == nullptr ) {
        return;
    } 

    updateHeight(*root);

    int balance = getBalance(*root);

    if(balance == 2) {
        int lb = getBalance((*root)->left);
        if(lb == 1) {
            RightRotate(root);
        }
        else if(lb == -1) {
            LeftRotate(&(*root)->left);
            RightRotate(root);
        }
    }
    else if(balance == -2) {
        int rb = getBalance((*root)->right);
        if(rb == -1) {
            LeftRotate(root);
        }
        else if(rb == 1) {
            RightRotate(&(*root)->right);
            LeftRotate(root);
        }
    }
}

int main() {
    Node * root = nullptr;

    Insert(&root,10);
    Insert(&root,20);
    Insert(&root,30);
    Insert(&root,40);
    Insert(&root,50);
    Insert(&root,60);
    Insert(&root,70);
    Insert(&root,80); 
    
    remove(&root,40);
    remove(&root,50);
    remove(&root,60);
    remove(&root,70);
    remove(&root,80);


    InOrder(root);

    return 0;
}