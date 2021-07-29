/*
    树的遍历

前序遍历：
先访问根节点，然后按照前序遍历访问根节点的各个子树。（根-左-右： 根-前序左-前序右）

后序遍历：
先按照后序遍历根节点的各个子树，然后访问根节点。（左-右-根： 后序左-后序右-根）

中序遍历：（只针对二叉树）
先中序遍历左子树，再访问根节点，最后中序遍历右子树。（左-根-右： 中序左-根-中序右）

层次序遍历：
从根节点开始，一层一层地遍历。

前序遍历和后序遍历，都可以使用递归或栈。

前序遍历的栈实现：
1. 根节点入栈；
2. 出栈一个节点，打印它；
3. 然后将出栈节点的所有子节点按从右往左的顺序入栈，goto 第2步，直至栈为空。

后序遍历的栈实现：
1. 根节点入栈
2. 栈顶节点的所有子节点一一检查，若没有被打印过（有打印标记），则入栈；（自右向左）
3. 再次检查当前栈顶节点的所有子节点：若全为NULL，或者全部都已经被打印过，则打印该栈顶节点，并出栈；
4. 返回第二步，直至栈空

层次序遍历的队列实现：
1. 根节点入队列
2. 打印根节点，并将根节点所有的子节点都移入队列，根节点出队
3. 然后按顺序重复以上第二步，即打印队首节点，将队首节点的所有的子节点加入队尾，将队首节点出队
4. 不断重复，直至队列为空

*/

#include <stack>
#include <set>
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right; 
    Node(int v, Node *l=nullptr, Node *r=nullptr):value(v), left(l), right(r) {}
};


void pre_order_recur(Node *head)
{
    if (head == nullptr) return;
    cout << head->value << " ";
    pre_order_recur(head->left);
    pre_order_recur(head->right);
}

void mid_order_recur(Node *head)
{
    if (head == nullptr) return;
    mid_order_recur(head->left);
    cout << head->value << " ";    
    mid_order_recur(head->right);
}

void post_order_recur(Node *head)
{
    if (head == nullptr) return;
    post_order_recur(head->left);
    post_order_recur(head->right);
    cout << head->value << " ";
}

struct StackNode {
    Node *node; 
    StackNode *next; 
    StackNode(Node *n) : node(n) {next = nullptr;}
};

// 非递归的前序 (自定义stack)
void pre_order_no_recur(Node *head) 
{
    StackNode *top = new StackNode(head);
    while(top != nullptr) {
        cout << top->node->value << " ";
        
        StackNode *old_top = top;  // pop from stack, record the old top 
        top = top->next; 
        
        if (old_top->node->right) {  // push right tree 
            StackNode *tmp = new StackNode(old_top->node->right);
            tmp->next = top;
            top = tmp;
        }
        if (old_top->node->left) {  // push left tree 
            StackNode *tmp = new StackNode(old_top->node->left);
            tmp->next = top;
            top = tmp;
        }
        delete old_top;
    }
}

// 非递归的前序 (STL stack)
void pre_order_no_recur_with_stl_stack(Node * head)
{
    if (head == nullptr) return;
    
    stack<Node *> mystack;
    mystack.push(head);
    
    while (!mystack.empty()) {
        Node * tmp = mystack.top();
        mystack.pop();
        if (tmp != nullptr) {
            cout << tmp->value << " ";
            if (tmp->right != nullptr) mystack.push(tmp->right);
            if (tmp->left  != nullptr) mystack.push(tmp->left);
        }
    }
}

// 非递归的后序
void post_order_no_recur(Node *head) 
{
    if (head == nullptr) return; 
    
    stack<Node *> mystack;
    mystack.push(head);
    set<Node *> donePointers;  // 记录子节点已经被压栈的节点
    
    auto it = donePointers.end();
    while (!mystack.empty()) {
        Node * tmp = mystack.top();
        if ( tmp == nullptr ) continue;
        
        it = donePointers.find(tmp);
        
        if ( it != donePointers.end() ) {  // 若该节点的子节点已经被压栈过了，则现在可以打印该节点
            cout << tmp->value << " ";
            mystack.pop();
            donePointers.erase(it);
        }
        else {  // 若该节点的子节点没有被压栈过，则现在不能打印该节点，而是应该将其子节点按右左的顺序压栈
            if (tmp->right != nullptr) mystack.push(tmp->right);
            if (tmp->left  != nullptr) mystack.push(tmp->left);
            donePointers.insert(tmp);
        }
    }
}


int main()
{
    Node a(40), b(20), c(50), d(10), e(30), f(60);
    a.left = &b; a.right = &c; 
    b.left = &d; b.right = &e;
    c.right = &f; 
    
    pre_order_recur(&a);  // 40 20 10 30 50 60
    cout << endl;
    pre_order_no_recur(&a);
    cout << endl;
    pre_order_no_recur_with_stl_stack(&a);
    cout << endl;
    
    mid_order_recur(&a);  // 10 20 30 40 50 60
    cout << endl;
    
    post_order_recur(&a);  // 10 30 20 60 50 40
    cout << endl;
    post_order_no_recur(&a);
    cout << endl;
    
    return 0;
}