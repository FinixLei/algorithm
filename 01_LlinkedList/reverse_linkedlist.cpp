#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node * next;
    Node(int d, Node * n=nullptr) : data(d), next(n) {}
};

// way 1 - Recursive
// This way would cause stack exhausting if too many nodes, e.g. 1e6
Node * reverse_linkedlist_recursively(Node * head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node * currNext = head->next; 
    Node * finalHead = reverse_linkedlist_recursively( currNext ); 
    currNext -> next = head; 
    head -> next = nullptr; 
    
    return finalHead; 
}

// way2 - Non-Recursive
Node * reverse_linkedlist(Node * head) {
    if (head == nullptr || head->next == nullptr) return head; 
    
    Node * p1 = head;
    Node * p2 = p1->next;
    Node * p3 = p2->next; 
    
    p1->next = nullptr;
    while (p3 != nullptr) {
        p2->next = p1;  // 每次只转一个指针
        p1 = p2; 
        p2 = p3; 
        p3 = p3->next;
    }
    p2->next = p1;  // 还差一次没有转
    
    return p2;
}

// way 2.1 - Non-Recursive + point to point 
void reverse_list(Node ** pHead)
{
    if (pHead == nullptr || *pHead == nullptr || (*pHead)->next == nullptr) return;
    
    Node * p1 = *pHead;
    Node * p2 = p1->next;
    Node * p3 = p2->next;
    
    p1->next = nullptr; 
    while (p3 != nullptr) {
        p2->next = p1; 
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    *pHead = p2;
}


void print_linkedlist(Node * head)
{
    while (head != nullptr) {
        cout << head->data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    Node *h = head; 
    for (int i=2; i<=20; ++i) {
        h->next = new Node(i);
        h = h->next; 
    }
    print_linkedlist(head);  // 1-20
    
    head = reverse_linkedlist_recursively(head);
    print_linkedlist(head);  // 20-1
    
    head = reverse_linkedlist(head); 
    print_linkedlist(head);  // 1-20
    
    reverse_list(&head);
    print_linkedlist(head);  // 20-1
    
    return 0;
}