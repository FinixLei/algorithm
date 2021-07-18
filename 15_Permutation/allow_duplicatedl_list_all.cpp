/*
  Given sevearl numbers and a figure n, 
  list all the sequences which contains n elements and the numbers mentioned above.
  There can be duplicated. 
  给定几个数字与一个数n，写出含有这几个数字的n位的全排列，允许有重复。
*/

#include <vector>
#include <iostream>
using namespace std;

static int total = 0;

void allow_duplicated_list_all(const vector<int>& origin, const int n, vector<int> & target_vec) {
    if (target_vec.size() == n) {
        for (auto i : target_vec) cout << i << " ";
        cout << endl;
        total++;
        return; 
    }
    
    for (int i=0; i<origin.size(); ++i) {
        target_vec.push_back(origin[i]);
        allow_duplicated_list_all(origin, n, target_vec);
        target_vec.pop_back();
    }
}

int main()
{
    const vector<int> origin{1, 2, 3}; 
    const int n = 5;

    vector<int> target_vec;
    allow_duplicated_list_all(origin, n, target_vec);
    cout << "total number is " << total << endl;
    return 0;
}
