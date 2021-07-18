/* 
    归并排序
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void print_container(T& c)
{
    for (auto i : c) cout << i << " ";
    cout << endl;
}

void do_merge(vector<int>&vec, int beg, int mid, int end)
{
    int i=beg, j=mid+1, k=0;
    vector<int> tmp; 
    
    while (i <= mid && j <= end) {
        if (vec[i] < vec[j]) {
            tmp.push_back(vec[i++]);
        }
        else {
            tmp.push_back(vec[j++]);
        }
    }
    
    while (i <= mid) {
        tmp.push_back(vec[i++]);
    }
    while (j <= end) {
        tmp.push_back(vec[j++]);
    }
    
    copy(tmp.begin(), tmp.end(), vec.begin()+beg);
}

void merge_sort(vector<int>& vec, int beg, int end) 
{
    if (beg >= end) return; 
    
    int mid = (beg + end)/2;
    merge_sort(vec, beg,   mid);
    merge_sort(vec, mid+1, end);
    do_merge(vec, beg, mid, end);
}

int main()
{
    vector<int> vec{98, 4, 3, 34, 24, 99};
    merge_sort(vec, 0, vec.size()-1);
    print_container(vec); 
    
    vec = {2, 1};
    merge_sort(vec, 0, vec.size()-1);
    print_container(vec); 
    
    vec = {3, 1, 2};
    merge_sort(vec, 0, vec.size()-1);
    print_container(vec); 
    
    return 0;
}