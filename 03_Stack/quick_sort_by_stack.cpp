#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
void print_vec(vector<T>& vec) 
{
    for (auto v : vec) cout << v << " ";
    cout << endl;
}

void qsort_with_stack(vector<int>& vec)
{
    if (vec.size() <= 1) return;
    
    stack<pair<int, int>> mystack;
    mystack.push(make_pair(0, vec.size()-1));
    
    while ( !mystack.empty() ) {
        pair<int, int> tmp = mystack.top();
        mystack.pop();
        int beg = tmp.first;
        int end = tmp.second;
        if (beg >= end) continue;
        
        int standard = vec[beg];
        while (beg < end) {
            while (beg < end && vec[end] >= standard) -- end;
            if (beg < end) vec[beg++] = vec[end];
            
            while (beg < end && vec[beg] <= standard) ++ beg; 
            if (beg < end) vec[end--] = vec[beg];
        }
        vec[beg] = standard;
        
        mystack.push(make_pair(tmp.first, beg-1));
        mystack.push(make_pair(beg+1, tmp.second));
    }
}


int main()
{
    vector<int> vec{10, 4, 20, 16, 37, 37, 99, 8, 5, 2, 1};
    print_vec(vec);
    qsort_with_stack(vec);
    print_vec(vec);
    
    vec = {2, 1};
    print_vec(vec);
    qsort_with_stack(vec);
    print_vec(vec);
    
    vec = {3, 1, 2};
    print_vec(vec);
    qsort_with_stack(vec);
    print_vec(vec);
    
    return 0;
}