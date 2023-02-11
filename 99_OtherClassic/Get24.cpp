#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const double TARGET_NUMBER = 24;
vector<string> Solutions;

class Number {
private:
    double val; 
    string exp; 

public:
    Number(double v=0, string e="") : val(v), exp(e) {}
    
    Number(double v) : val(v) {
        stringstream ss;
        ss << val;
        exp = ss.str();
    }
    
    Number(int v) : val(v) {
        stringstream ss;
        ss << val;
        exp = ss.str();
    }
    
    Number(const Number& other) {
        val = other.val;
        exp = other.exp;
    }
    
    void operator = (const Number& other) {
        if (this == &other) return;
        this->val = other.val;
        this->exp = other.exp;
    }
    
    friend Number operator + (Number& a, Number& b) {
        Number res;
        res.val = a.getVal() + b.getVal();
        
        stringstream ss;
        ss << "(" << a.getExp() << "+" << b.getExp() << ")";
        res.exp = ss.str();
        return res;
    }
    
    friend Number operator - (Number& a, Number& b) {
        Number res;
        res.val = a.getVal() - b.getVal();
        
        stringstream ss;
        ss << "(" << a.getExp() << "-" << b.getExp() << ")";
        res.exp = ss.str();
        return res;
    }
    
    friend Number operator * (Number& a, Number& b) {
        Number res;
        res.val = a.getVal() * b.getVal();
        
        stringstream ss;
        ss << "(" << a.getExp() << "*" << b.getExp() << ")";
        res.exp = ss.str();
        return res;
    }
    
    friend Number operator / (Number& a, Number& b) {
        Number res;
        res.val = a.getVal() / b.getVal();
        
        stringstream ss;
        ss << "(" << a.getExp() << "/" << b.getExp() << ")";
        res.exp = ss.str();
        return res;
    }
    
    double getVal() { return val; }
    string getExp() { return exp; }
};

// original array = [a, b, restArray]
struct DataSet {
    Number a; 
    Number b; 
    vector<Number> restArray; 
    
    DataSet(Number a=0, Number b=0) : a(a), b(b) {}
};

vector<Number> genTwoNumResult(Number a, Number b) {
    vector<Number> result;
    result.push_back(a+b);
    result.push_back(a*b);
    result.push_back(a-b);
    result.push_back(b-a);
    result.push_back(a/b);
    result.push_back(b/a);
    return result;
}

// Get 2 numbers out of one array 
// Save all the possibilities to one vector 
vector<DataSet> getTwoOutofArray(const vector<Number>& vec) {
    int vecSize = vec.size();
    
    vector<DataSet> result = {};
    if (vecSize < 2) return result;
    
    vector<pair<int, int>> indexPairs; 
    
    for (int i=0; i<vecSize-1; i++) {
        for (int j=i+1; j<vecSize; j++) {
            indexPairs.push_back({i, j});
        }
    }
    
    for (pair<int,int>& p : indexPairs) {
        DataSet tmp(vec[p.first], vec[p.second]);
        
        for (int i=0; i<vecSize; i++) {
            if (i != p.first && i != p.second) {
                tmp.restArray.push_back(vec[i]);
            }
        }
        result.push_back(tmp);
    }
    return result; 
}

// Recusive Function: reduce the size of array by one for one time 
void resolve(vector<Number>& array) {
    if (array.size() <= 0) return;
    
    if (array.size() == 1) {
        if (array[0].getVal() - TARGET_NUMBER < 1e-6 && 
            TARGET_NUMBER - array[0].getVal() < 1e-6) {
                Solutions.push_back(array[0].getExp()); 
            }
        return; 
    }
    
    vector<vector<Number>> newArrays; 
    vector<DataSet> middleSets = getTwoOutofArray(array);
    
    for (auto& dataSet : middleSets) {
        // Get 2 numbers out of one array, then the 2 numbers can generate 6 different numbers 
        vector<Number> newNumbers = genTwoNumResult(dataSet.a, dataSet.b);
        
        for (auto& newNumber : newNumbers) {
            vector<Number> newArray = dataSet.restArray;
            newArray.push_back(newNumber);
            newArrays.push_back(newArray);
        }
    }
    
    for (auto& vecNum : newArrays) resolve(vecNum);
}

void resolve_puzzle()
{
    int a=0, b=0, c=0, d=0;
    cout << "请输入4个数字(以空格间隔)：";
    cin >> a >> b >> c >> d; 
    
    vector<Number> vec{Number(a), Number(b), Number(c), Number(d)};
    Solutions = {};
    resolve(vec);
    
    sort(Solutions.begin(), Solutions.end());
    Solutions.erase(unique(Solutions.begin(), Solutions.end()), Solutions.end());
    
    for (auto& s : Solutions) cout << s << " = " << TARGET_NUMBER << endl;
    cout << "总共有 " << Solutions.size() << " 种方法：" << endl;
}

int main()
{
    while (true) {
        resolve_puzzle();
        
        char answer = 'N';
        cout << "要继续吗？[Y|N]:";
        cin >> answer; 
        if (answer == 'Y' || answer == 'y') continue;
        else break;
    }
    return 0;
}