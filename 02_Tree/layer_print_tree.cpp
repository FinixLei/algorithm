#include <queue> 
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int d, Node *l=nullptr, Node *r=nullptr) : data(d), left(l), right(r) {}
    
};

void layer_print(Node * head)
{
    if (head == nullptr) return;
    
    queue<Node *> node_queue;
    node_queue.push(head);
    
    while (!node_queue.empty()) {
        Node * tmp = node_queue.front();
        node_queue.pop();
        
        if (tmp != nullptr) {
            cout << tmp->data << " "; 
            if (tmp->left != nullptr)  node_queue.push(tmp->left);
            if (tmp->right != nullptr) node_queue.push(tmp->right);
        }
    }
    
}

int main()
{
    Node a(10), b(20), c(30), d(40), e(50), f(60);
    a.left  = &b;
    a.right = &c;
    b.left  = &d;
    b.right = &e;
    c.left  = &f; 
    
    layer_print(&a);
    
    return 0;
}