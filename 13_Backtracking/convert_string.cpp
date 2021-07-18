#include <vector>
#include <iostream>
#include <deque>
#include <string>
#include <climits>
using namespace std;


vector<int> getOneCharDiffVec(vector<string>& dict, const vector<int>& visited, const string& str)
{
    vector<int> result;
  
    for (int i=0; i<dict.size(); i++) {
        if (visited[i] == 1) continue;
        
        int count = 0;
        for(int pos=0; pos<str.size(); pos++) {
            if (str[pos] != dict[i][pos]) {
                count ++;
                if (count > 1) break;
            }
        }
        if (count == 1) result.push_back(i);
    }
    return result;
}

int _convert(vector<string>& dict, vector<int>& visited, deque<string>& stackWord, string end)
{
    string currStr = stackWord.front(); 
    if (currStr == end) {
       for (auto str : stackWord) cout << str << " " ;
       cout << endl;
       return stackWord.size() - 1;
    }
  
    vector<int> oneDiffVec = getOneCharDiffVec(dict, visited, currStr);
    
    if (oneDiffVec.size() == 0) return -1;
  
    int minValue = INT_MAX;
    for (int i=0; i<oneDiffVec.size(); i++) {
        if (visited[oneDiffVec[i]] == 1) continue;
      
        stackWord.push_front(dict[oneDiffVec[i]]);
        visited[oneDiffVec[i]] = 1;
       
        int tmp_result = _convert(dict, visited, stackWord, end);
        if (tmp_result != -1 && tmp_result < minValue) {
            minValue = tmp_result;
        }
      
        visited[oneDiffVec[i]] = 0; 
        stackWord.pop_front();
    }
   
   return (minValue == INT_MAX ? -1 : minValue); 
}

int convert(vector<string>& dict, string beginWord, string endWord)
{
    if (beginWord == endWord) return 0;
    
    deque<string> stackWord; 
    vector<int> visited(dict.size(), 0);  // 0 - not visited, 1 - visited
    
    stackWord.push_front(beginWord);
    for (int i=0; i<dict.size(); ++i) {
        if (dict[i] == beginWord) visited[i] = 1;
    }
    return _convert(dict, visited, stackWord, endWord);   
}

int main()
{
    vector<string> dict = {"aaa", "aab", "aac", "xaa", "bxb", "bbb", "ccc", "axb", "acb"};
    string begin = "aaa";
    string end = "bbb";
    
    int convert_num = convert(dict, begin, end);
    cout << "Min convert number: " << convert_num << endl;
    
    return 0;
}

/* Run Result: 

$./a.out
bbb bxb axb aab aaa
bbb bxb axb acb aab aaa
bbb bxb axb aab aaa aac aaa
bbb bxb axb acb aab aaa aac aaa
bbb bxb axb aab aac aaa
bbb bxb axb acb aab aac aaa
bbb bxb axb aab aaa xaa aaa
bbb bxb axb acb aab aaa xaa aaa
bbb bxb axb aab aac aaa xaa aaa
bbb bxb axb acb aab aac aaa xaa aaa
Min convert number: 4
*/
