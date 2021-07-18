/* 
令E= {e1 , ..., en }表示 n 个元素的集合，目标是生成该集合的所有排列方式。
令 
- Ei 为 E中移去元素 i 以后所获得的集合，
- perm (X) 表示集合 X 中元素的排列方式，
- ei.perm(X)表示在perm(X)中的每个排列方式的前面均加上ei以后所得到的排列方式。
例如，
如果E= {a, b, c}，那么:
- E1          = {b, c}
- perm(E1 )   = (b c, c b)
- e1.perm(E1) = (a b c, a c b)

对于递归的基本部分，采用n = 1。当只有一个元素时，只可能产生一种排列方式。
当n > 1时，
    perm(E) = e1.perm (E1) + e2.perm(E2 ) + ... + en.perm(En)
这种递归定义形式是采用n个perm(X)来定义perm(E), 其中每个X包含n-1个元素。
至此，一个完整的递归定义所需要的基本部分和递归部分都已完成。
*/

#include <iostream>
#include <vector>
using namespace std;

static int total_number = 0;

void print_list(const vector<int>& result) {
    for (auto v : result) cout << v << " ";
    cout << endl;
}

void list_all(vector<int>& vec, int beg, int end, vector<int>& result)
{
    if (beg > end) {
        print_list(result);
        total_number ++;
        return;
    }
    
    for (int i=beg; i<=end; i++) {
        swap(vec[beg], vec[i]);
        result.push_back(vec[i]);
        list_all(vec, beg+1, end, result);
        result.pop_back();
        swap(vec[beg], vec[i]);
    }
}

int main()
{
    vector<int> vec{1, 2, 3};
    vector<int> result;
    result.reserve(vec.size());
    
    list_all(vec, 0, vec.size()-1, result);
    cout << "total_number = " << total_number << endl;
    
    return 0;
}
