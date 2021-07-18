/*
背包问题：
有一个背包，最多放 max_number 个东西，最多放max_weight KG的重量。
现有N个物品，重量存放在items数组中。
问：该背包最多能装多重的重量，怎么装？
*/


#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;


template<typename T> print_container(T& t) 
{
    for (auto i : t) {
        cout << i << " ";
    }
    cout << endl;
}

// 物品列表
vector<int> items{23, 19, 17, 13, 11, 7, 5, 3, 2};

// 背包
vector<int> bag; 

// 最大放120kg
int max_weight = 100;
// 最多放10个物品
int max_number = 5;
// 当前重量最大记录
int max_reach = 0;

void cal_bag(int current_index, int current_weight)
{
    if ((bag.size() <= max_number && current_weight == max_weight) || // 已达最大重量
        (bag.size() == max_number && current_weight > max_reach)) {   // 已超过当前最大记录且已达到最大物品个数
        if (current_weight > max_reach) max_reach = current_weight;
        cout << "current_weight=" << current_weight << ", bag.size=" << bag.size() << ", current_index=" << current_index << endl;
        print_container(bag);
        cout << "sum = " << accumulate(bag.begin(), bag.end(), 0) << endl;
        return;
    }
    
    if (current_index+1 <= items.size()) {  // 尚未超出items数组的范畴
        cal_bag(current_index+1, current_weight);  // 假设不取当前物品放入包内
        
        if (items[current_index] + current_weight <= max_weight) {  // 取当前物品放入包内
            bag.push_back(items[current_index]);
            cal_bag(current_index+1, items[current_index]+current_weight);
            bag.pop_back();
        }
    }
}

int main()
{
    sort(items.begin(), items.end());
    print_container<vector<int>>(items);
    cal_bag(0, 0);
    return 0;
}
