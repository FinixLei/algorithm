#include <iostream>
#include <stack>
using namespace std;

int array[] = {324, 56, 3, 46, 46, 54, 56, 322, 59, 72, 58, 98};
int size = sizeof(array)/sizeof(int);

void print_array(int* array, int start, int end)
{
    for (int i=start; i<=end; ++i) cout << array[i] << " ";
    cout << endl;
}

void qs(int *array, int start, int end)
{
    if (start >= end) return;
    
    stack<pair<int, int>> mystack;
    mystack.push(make_pair(start, end));
    
    while ( !mystack.empty() ) {
        pair<int, int> top = mystack.top();
        int front = top.first;
        int back  = top.second;
        int start = front;
        int end   = back;

        int t = array[front]; 
        while(front != back) {
            while (front < back && array[back] > t)
                back--; 
            if (front < back) array[front++] = array[back];
            
            while (front < back && array[front] <= t) 
                front ++;
            if (front<back) array[back--] = array[front];
        }
        array[front] = t;
        
        mystack.pop();

        if (start < front-1) mystack.push(make_pair(start, front-1));
        if (front+1 < end)   mystack.push(make_pair(front+1, end));
    }
}

int main()
{
    int size = sizeof(array)/sizeof(array[0]);
    print_array(array, 0, size-1);
    
    qs(array, 0, size-1);
    print_array(array, 0, size-1);
    
    return 0;
}
