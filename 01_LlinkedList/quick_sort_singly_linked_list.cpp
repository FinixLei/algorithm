#include <iostream>
using namespace std;

struct Node {
  int val;
  Node * next;
  Node(int v, Node * p=nullptr) : val(v), next(p) {}
};

void print_linked_list(Node *p) {
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

void delete_linked_list(Node *p) {
  while (p != nullptr) {
    Node * tmp = p->next;
    delete p;
    p = tmp;
  }
}

// For [head, tail), put the head in the middle, so that, 
// left nodes <= head <= right nodes
// Return: the latest head node of the singly linked list 
Node * quick_sort_singly_linked_list(Node * head, Node * tail)
{
  if (head == tail || head->next == tail) return head;
  
  Node *h1 = nullptr, *h1p = nullptr;
  Node *h2 = head, *h2p = head;
  
  Node * p = head->next; 
  while (p != tail) {
    if (p->val <= head->val) {
      if (h1) {
        h1p->next = p;
        h1p = p;
      }
      else { // h1 is nullptr, i.e. this is the first smaller node
        h1 = h1p = p;
      }
    }
    else { // p->val > head->val 
      h2p->next = p; 
      h2p = p;
    }
    p = p->next; 
  }
  
  // Join the 2 linked list 
  if (h1) h1p->next = head;
  h2p->next = tail; 
  
  if (h1 == nullptr) { // head is the minimum node in [head, tail)
    head->next = quick_sort_singly_linked_list(head->next, tail);
    return head;
  }

  Node * p1 = quick_sort_singly_linked_list(h1, head);
  Node * p2 = quick_sort_singly_linked_list(head->next, tail);
  head->next = p2;
  return p1;   
}

void test_case_01()
{
  Node * a1 = new Node(10);
  Node * a2 = new Node(5);
  Node * a3 = new Node(8);
  Node * a4 = new Node(20);
  Node * a5 = new Node(26);
  Node * a6 = new Node(18);
  
  a1->next = a2;
  a2->next = a3;
  a3->next = a4;
  a4->next = a5;
  a5->next = a6;
  
  print_linked_list(a1);
  Node * h = quick_sort_singly_linked_list(a1, nullptr);
  print_linked_list(h);
  
  delete_linked_list(h);
}

int main()
{
  test_case_01();
  return 0;
}
