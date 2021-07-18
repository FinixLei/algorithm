/*
    给定一个n位的数字，从中去掉k位(k<n),使得新数字最小。
    
    思路：
    贪心算法
    一路扫描过去，若当前位置数字比后一位大，则删除当前位置数字，否则继续后移。
*/

#include <stdlib.h>
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    char value; 
    Node * next; 
    Node(int v):value(v), next(NULL){}
};

void print_list(Node * p) 
{
    while(p) {
        cout << p->value;
        p = p->next;
    }
    cout << endl;
}

void release_list(Node *p) 
{
    Node *tmp;
    while(p) {
        tmp = p->next; 
        delete p; 
        p = tmp;
    }
}

int main()
{
    string number;
    int k; 
    number = "12345"; k=2;
    number = "54321"; k=2;
    number = "40099"; k=2;
    number = "4556847594546"; k=5;
    cout << number << endl;
    
    // construct the linked list
    vector<char> vec(number.begin(), number.end());
    Node *head = NULL, *t = NULL;
    bool started = false;
    for (auto ch : vec) {
        if (!started) {
            head = new Node(ch);
            t = head;
            started = true;
        }
        else {
            t->next = new Node(ch);
            t = t->next; 
        }
    }
    
    // Calculate
    Node *p = NULL, *pre = NULL;
    while(k>0) {
        print_list(head);
        pre = p = head;
        
        while (p != NULL) {
            if (p->next == NULL) {
                pre->next = NULL;
                delete p;
                k--;
                break;
            }
            else if (p->value > p->next->value) {
                if (p == head) {
                    head = p->next; 
                    delete p;
                }
                else {
                    pre->next = p->next; 
                    delete p; 
                    p = pre->next;
                }
                k--; 
                break;
            }
            else {
                pre = p; 
                p = p->next; 
            }
        }
    }
    
    print_list(head);
    release_list(head);
    return 0;
}
