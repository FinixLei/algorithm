#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    
    Node(int d=0) : data(d), next(nullptr){}
};

void print_list(Node * head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void delete_list(Node *head) {
    while (head != nullptr) {
        Node * tmp = head; 
        head = head->next;
        delete tmp;
    }
}

void quick_sort_single_list(Node * beg, Node * end=nullptr)
{
    if (beg == nullptr || beg == end) return;
    
    int base = beg->data; 
    Node * p1 = beg; 
    Node * p2 = beg->next; 
    
    while (p2 != end) {
        if (p2->data <= base) {
            p1 = p1->next;
            swap(p1->data, p2->data);
        }
        p2 = p2->next;
    }
    
    swap(p1->data, beg->data);
    quick_sort_single_list(beg, p1);
    quick_sort_single_list(p1->next, end);
    
}

int main()
{
    Node n1(1), n2(6), n3(9);
    Node n4(5), n5(10), n6(17);
    Node n7(8), n8(7), n9(2);
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    
    print_list(&n1);
    
    quick_sort_list(&n1);
    print_list(&n1);
    
    return 0;
}