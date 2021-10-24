#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void print_vec(vector<T>& vec)
{
    for (auto& v : vec) cout << v << " ";
    cout << endl;
}


void my_quick_sort(vector<int>& vec, int beg, int end)
{
    if (beg >= end) return;
    
    int p1 = beg, p2 = end;
    int tmp = vec[beg];
    
    while (p1 < p2) 
    {
        // 既然要拿第一个元素作为标准，那么就必须从后往前开始比较；
        // 这是因为要把第一个元素的位置空出来，放比第一个元素小的元素，那就只能在后面找到小的，然后放进来；
        // 如果从前开始比较，当发现更小元素的时候，就很难移动；
        
        while (vec[p2] >= tmp && p1< p2) p2--;
        if (p1 < p2) vec[p1] = vec[p2];
        
        while (vec[p1] < tmp && p1 < p2) ++ p1; 
        if (p1 < p2) vec[p2] = vec[p1];
    }
    vec[p1] = tmp;  // p1 must be equal to p2
    
    my_quick_sort(vec, beg, p1-1);
    my_quick_sort(vec, p1+1, end);
}

int main()
{
    vector<int> vec{3, 8, 2, 10, 7, 6, 5, 9, 1, 3, 4};
    
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {1, 2, 3};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {3, 2, 1};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {1, 2};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {2, 1};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {1};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {1, 1};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    vec = {1, 1, 1};
    print_vec(vec);
    my_quick_sort(vec, 0, vec.size()-1);
    print_vec(vec);
    cout << "--------------------------------\n";
    
    return 0;
}
