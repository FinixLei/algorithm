#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int>& vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

// 两两比较，直到最大的排到最后
// 最后一次交换处，即为下一次做冒泡排序的最后位置，但要注意边界条件（即下文的j=i+1,而不是j=i）
void bubble_sort(vector<int>& vec)
{
    int n = vec.size();
    
    while (n > 0) {
        int i = 0;  // compare the adjacent values 
        int j = 0;  // record the last i 
        while (i < n-1) {
            if (vec[i] > vec[i+1]) {
                swap(vec[i], vec[i+1]);
                // later let n=j, and cannot use vec[n], so j=i+1, not j=i 
                j = i+1; 
            }
            i ++;
        }
        n = j;
    }
}


int main()
{
    vector<int> array{0, 19, 88, 2, 43, 22, 99, 17};
    print_vec(array);
    
    bubble_sort(array);
    print_vec(array);
    
    array = {0};
    bubble_sort(array);
    print_vec(array);
    
    array = {0, 3, -1};
    bubble_sort(array); 
    print_vec(array);
    
    return 0;
}
