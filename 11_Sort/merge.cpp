#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    for (auto i : vec) cout << i << " ";
    cout << endl;
}

void merge_sort(vector<int>& vec, vector<int>& result, int start, int end)
{
    if (start >= end) return;
    
    int mid = (end-start)/2 + start; 
    
    merge_sort(vec, result, start, mid);
    merge_sort(vec, result, mid+1, end);
    
    int i = start; 
    int j = mid + 1;
    int s = start; 
    
    while (i<=mid && j<=end) {
        if (vec[i] < vec[j]) {
            result[s++] = vec[i++]; 
        }
        else {
            result[s++] = vec[j++];
        }
    }
    
    if (i<=mid && j>end) {
        for (int k=i; k<=mid;) {
            result[s++] = vec[k++];
        }
    }
    
    if (i>mid && j<=end) {
        for (int k=j; k<=end; ) {
            result[s++] = vec[k++];
        }
    }
    
    for (int k=start; k<=end; k++) {
        vec[k] = result[k];
    }
}

int main()
{
    vector<int> vec{10, 8, 22, 15, 33, 44, 88, 76, 32};
    print_vector(vec);
    
    int n = vec.size();
    vector<int> result(n);
    
    merge_sort(vec, result, 0, n-1);
    print_vector(vec);
    
    vec = {0};
    merge_sort(vec, result, 0, 0);
    print_vector(vec);
    
    vec = {2, 1};
    merge_sort(vec, result, 0, 1);
    print_vector(vec);
    
    vec = {3, 1, 2};
    merge_sort(vec, result, 0, 2);
    print_vector(vec);
    
    return 0;
}