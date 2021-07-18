/* 
    归并排序
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
print_container(T& c)
{
    for (auto i : c) {
        cout << i << " ";
    }
    cout << endl;
}

void do_merge(vector<int>&vec, int p, int q, int r)
{
    int i=p, j=q+1, k=0;
    vector<int> tmp; 
    
    while (i<=q && j<=r) {
        if (vec[i] < vec[j]) {
            tmp.push_back(vec[i++]);
        }
        else {
            tmp.push_back(vec[j++]);
        }
    }
    while (i<=q) {
        tmp.push_back(vec[i++]);
    }
    while (j<=r) {
        tmp.push_back(vec[j++]);
    }
    
    copy(tmp.begin(), tmp.end(), vec.begin()+p);
}

void merge_sort(vector<int>& vec, int p, int r) 
{
    // cout << "p = " << p << ", r = " << r << endl;
    if (p>=r) return; 
    
    int q = (p+r)/2;
    merge_sort(vec, p, q);
    merge_sort(vec, q+1, r);
    do_merge(vec, p, q, r);
}

int main()
{
    int array[] = {98, 4, 3, 34, 24, 99};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));    
    print_container<vector<int>>(vec); 
    
    merge_sort(vec, 0, vec.size()-1);
    print_container<vector<int>>(vec); 
    
    return 0;
}