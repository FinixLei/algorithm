#include <iostream>
using namespace std;

struct Node {
    char value;
    Node *left;
    Node *right; 
    Node(int v):value(v), left(NULL), right(NULL){}
};

struct StackNode {
    Node *node; 
    StackNode *next; 
    StackNode(Node *n):node(n), next(NULL){}
};

void tree_dfs_with_stack(Node *root) 
{
    if (root == NULL) return; 
    
    StackNode *top = new StackNode(root);
    while (top != NULL) {
        cout << top->node->value << " ";
        StackNode *old_top = top;
        top = top->next;  // pop 
        
        if (old_top->node->right != NULL) {
            StackNode *tmp = new StackNode(old_top->node->right);
            tmp->next = top;
            top = tmp;  // push 
        }
        if (old_top->node->left != NULL) {
            StackNode *tmp = new StackNode(old_top->node->left);
            tmp->next = top;
            top = tmp;  // push 
        }
        delete old_top; 
    }
}

void tree_dfs_recursively(Node *root)
{
    if (root == NULL) return;
    
    cout << root->value << " ";
    tree_dfs_recursively(root->left);
    tree_dfs_recursively(root->right);
}

int main()
{
    Node *a = new Node('A');
    Node *b = new Node('B');
    Node *c = new Node('C');
    Node *d = new Node('D');
    Node *e = new Node('E');
    Node *f = new Node('F');
    Node *g = new Node('G');
    a->left = b; 
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    tree_dfs_with_stack(a);
    cout << endl;
    
    tree_dfs_recursively(a);
    cout << endl;
    
    return 0;
}
