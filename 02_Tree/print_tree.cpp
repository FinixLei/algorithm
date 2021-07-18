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

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right; 
    int flag;  // 0 or 1, only for 后序遍历的栈实现
    Node(int v):value(v) {left=right=NULL; flag=0;}
};


void pre_order_recur(Node *head)
{
    if (head == NULL) return;
    cout << head->value << " ";
    pre_order_recur(head->left);
    pre_order_recur(head->right);
}

void mid_order_recur(Node *head)
{
    if (head == NULL) return;
    mid_order_recur(head->left);
    cout << head->value << " ";    
    mid_order_recur(head->right);
}

void post_order_recur(Node *head)
{
    if (head == NULL) return;
    post_order_recur(head->left);
    post_order_recur(head->right);
    cout << head->value << " ";
}

struct StackNode {
    Node *node; 
    StackNode *next; 
    StackNode(Node *n) : node(n) {next = NULL;}
};

// 非递归的前序
void pre_order_norecur(Node *head) 
{
    StackNode *top = new StackNode(head);
    while(top != NULL) {
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

// 非递归的后序
void post_order_norecur(Node *head) 
{
    if (head == NULL) return; 
    
    StackNode *top = new StackNode(head);
    do {
        StackNode *old_top = top;
        if (old_top->node->right && old_top->node->right->flag==0) {
            StackNode *tmp = new StackNode(old_top->node->right);
            tmp->next = top;
            top = tmp;
        }
        if (old_top->node->left && old_top->node->left->flag==0) {
            StackNode *tmp = new StackNode(old_top->node->left);
            tmp->next = top;
            top = tmp;
        }
        if ((top->node->left == NULL && top->node->right == NULL) || 
            (top->node->left == NULL && top->node->right->flag == 1) || 
            (top->node->right == NULL && top->node->left->flag == 1) || 
            (top->node->left->flag == 1 && top->node->right->flag == 1)) {
                cout << top->node->value << " ";
                top->node->flag = 1;
                StackNode *tmp = top;
                top = top->next; 
                delete tmp; 
        }
    } while (top != NULL);
}


int main()
{
    Node a(40), b(20), c(50), d(10), e(30), f(60);
    a.left = &b; a.right = &c; 
    b.left = &d; b.right = &e;
    c.right = &f; 
    
    pre_order_recur(&a);  // 40 20 10 30 50 60
    cout << endl;
    pre_order_norecur(&a);
    cout << endl;
    
    mid_order_recur(&a);  // 10 20 30 40 50 60
    cout << endl;
    
    post_order_recur(&a);  // 10 30 20 60 50 40
    cout << endl;
    post_order_norecur(&a);
    cout << endl;
    
    return 0;
}