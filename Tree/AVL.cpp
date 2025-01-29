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
    this->height = 1;
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

    if((*root)->val > val) {
        Insert(&(*root)->left,val);
    }
    else {
        Insert(&(*root)->right,val);
    }

    UpdateHeight(*root);

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

Node * findLeftMax(Node * root) {
    Node * max = root->left;
    while(max&&max->right) {
        max = max->right;
    }
    return max;
}

void remove(Node ** root,int val) {
    if(*root == nullptr) {
        return;
    } 

    if((*root)->val > val) {
        remove(&(*root)->left,val);
    }
    else {
        remove(&(*root)->right,val);
    }

    if((*root)->val == val) {
        Node * temp = *root;
        if( !(*root)->left && !(*root)->right) {
            delete *root;
            *root = nullptr;
        }
        else if( (*root)->left && !(*root)->right ) {
            *root = (*root)->left;
            delete temp;
        }
        else if( !(*root)->left && (*root)->right) {
            *root = (*root)->right;
            delete temp;
        }
        else {
            Node * leftMax = findLeftMax(*root);
            (*root)->val = leftMax->val;
            remove(&(temp)->left,leftMax->val);
        }

        if(*root == nullptr) {
            return;
        }

        UpdateHeight(*root);

        int balance = Balance(*root),lb = Balance((*root)->left),rb = Balance((*root)->right);

        if(balance == 2) {
            if(lb == 1) {
                RightRotato(root);
            }
            else if(lb == -1) {
                LeftRotato(&(*root)->left);
                RightRotato(root);
            }
        }
        else if(balance == -2) {
            if(rb == -1) {
                LeftRotato(root);
            }
            else if(rb == 1) {
                RightRotato(&(*root)->right);
                LeftRotato(root);
            }
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

    InOrder(root);

    return 0;
}