#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int d):data(d){next = NULL;}
};

// way 1 - in a recursive way
Node * reverse_linkedlist_recursively(Node * head) {
    if (head == NULL or head->next == NULL) return head;
    
    Node *current_next = head->next;
    Node *final_head = reverse_linkedlist_recursively(current_next);
    current_next->next = head;
    head->next = NULL;
    
    return final_head;
}

// way2 - in a non-recursive way
Node * reverse_linkedlist(Node * head) {
    if (head == NULL or head->next == NULL) return head;
    
    Node *p1 = head; 
    Node *p2 = p1->next;
    Node *p3 = p2->next;
    head->next = NULL; 
    
    while (true) {
        p2->next = p1; 
        p1 = p2; 
        p2 = p3;
        if (p3 != NULL) p3 = p3->next; 
        else return p1;
    }
}

void print_linkedlist(Node * head) {
    while (head != NULL) {
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    Node *h = head; 
    for (int i=2; i<=20; ++i) {  // Or, i<=2
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
