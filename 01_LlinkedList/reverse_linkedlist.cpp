#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node * next;
    Node(int d, Node * n=nullptr) : data(d), next(n) {}
};

// way 1 - Recursive
Node * reverse_linkedlist_recursively(Node * head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node * curr = head;
    Node * currNext = head->next; 
    
    Node * final_head = reverse_linkedlist_recursively( currNext ); 
    
    currNext -> next = curr; 
    curr -> next = nullptr; 
    
    return final_head; 
}

// way2 - Non-Recursive
Node * reverse_linkedlist(Node * head) {
    if (head == nullptr || head->next == nullptr) return head; 
    
    Node * p1 = head;
    Node * p2 = p1->next;
    Node * p3 = p2->next; 
    
    while (p3 != nullptr) {
        p2->next = p1;  // 每次只转一个指针
        p1 = p2; 
        p2 = p3; 
        p3 = p3->next;
    }
    p2->next = p1;  // 还差一次没有转
    head -> next = nullptr; 
    
    return p2;
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
    
    return 0;
}