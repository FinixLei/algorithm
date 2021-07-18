#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int> vec) 
{
    for (auto v : vec) cout << v << " ";
    cout << endl;
}

vector<vector<int>> all_lists;

void list_all_n_of_m(const vector<int>& array, int n, int start, vector<int>& one_result)
{
    if (0 == n) {
        all_lists.push_back(one_result);  // or print here
        return;
    }
    
    int end = array.size() - n; 
    
    for (int i=start; i<=end; i++) {
        one_result.push_back(array[i]);
        list_all_n_of_m(array, n-1, i+1, one_result);
        one_result.pop_back();
    }
}

int main()
{
    const int n = 3;
    const vector<int> array({1, 2, 3, 4, 5});
    
    vector<int> one_result; 
    list_all_n_of_m(array, n, 0, one_result);
    
    for (auto vec : all_lists) {
        print_vec(vec);
    }
    cout << "Total count: " << all_lists.size() << endl;
    
    return 0;
}