#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

struct LinkedNode {
    TreeNode * p;
    LinkedNode * next; 
    LinkedNode(TreeNode *np) : p(np), next(nullptr) {}
};

template <typename T>
void deleteList(T* root) {
    if (root == nullptr) return;
    do {
        T* tmp = root->next; 
        delete root; 
        root = tmp; 
    } while (root != nullptr);
}

template <typename T>
void printList(T* root) {
    while (root != nullptr) {
        if (root->p != nullptr) {
            cout << root->p->data << " ";
        }
        root = root->next;
    }
    cout << endl;
}

bool searchTargetTreeNode(TreeNode * root, TreeNode * target, LinkedNode** h)
{
    if (root == nullptr || target == nullptr) return false;
    
    LinkedNode * tmp = new LinkedNode(root);
    
    if (*h == nullptr) {
        (*h) = tmp;
    }
    else {
        (*h)->next = tmp;
    }
    
    if (root == target) return true;
    if ( searchTargetTreeNode(root->left, target, &tmp) )  return true; 
    if ( searchTargetTreeNode(root->right, target, &tmp) ) return true;

    delete tmp;
    (*h)->next = nullptr;
    return false;
}

TreeNode * findSharedAncestor(TreeNode * root, TreeNode *a, TreeNode *b) 
{
    if (root == nullptr || a == nullptr || b == nullptr) return nullptr;
    
    LinkedNode * h1 = nullptr;
    bool bFoundA = searchTargetTreeNode(root, a, &h1);
    if (!bFoundA) {
        deleteList(h1);
        return nullptr; 
    }
    else {
        printList(h1);
    }
    
    LinkedNode * h2 = nullptr;
    bool bFoundB = searchTargetTreeNode(root, b, &h2);
    if (!bFoundB) {
        deleteList(h2);
        return nullptr;
    }
    else {
        printList(h2);
    }
    
    TreeNode * result = nullptr;
    
    while (true) {
        if (h1->p == h2->p) {
            result = h1->p; 
        }
        else {
            break;
        }
        
        if (h1->next == nullptr || h2->next == nullptr) break;
        
        h1 = h1->next;
        h2 = h2->next;
    }
    
    deleteList(h1);
    deleteList(h2);
    
    return result;
    
}

int main()
{
    TreeNode n1(1), n2(2), n3(3);
    TreeNode n4(4), n5(5), n6(6);
    TreeNode n7(7), n8(8), n9(9);
    
    n1.left  = &n2;
    n1.right = &n3;
    n2.left  = &n4;
    n2.right = &n5;
    n3.left  = &n6;
    n3.right = &n7;
    n4.left  = &n8;
    n6.right = &n9;
    
    TreeNode * result = findSharedAncestor(&n1, &n8, &n5);
    cout << "shared ancestor is " << result->data << endl;
    return 0;
}
