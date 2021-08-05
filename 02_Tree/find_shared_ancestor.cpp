#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data; 
    TreeNode * left;
    TreeNode * right;
    TreeNode (int d, TreeNode* l=nullptr, TreeNode* r=nullptr) : data(d), left(l), right(r) {}
};

void print_vector(vector<TreeNode*> & vec) 
{
    for (auto v : vec) cout << v->data << " ";
    cout << endl;
}

bool find_a_path(TreeNode * head, int data, vector<TreeNode *>& myvec)
{
    if (head == nullptr) return false;
    
    myvec.push_back(head);
    if (head->data == data) return true;
    
    if (find_a_path(head->left,  data, myvec)) return true; 
    if (find_a_path(head->right, data, myvec)) return true;
    
    myvec.pop_back();
    return false;
}

TreeNode * get_shared_ancestor(TreeNode * head, int d1, int d2)
{
    vector<TreeNode *> v1;
    vector<TreeNode *> v2;
    
    if ( find_a_path(head, d1, v1) ) print_vector(v1);
    else return nullptr;
    if ( find_a_path(head, d2, v2) ) print_vector(v2);
    else return nullptr;
        
    TreeNode * result = nullptr;
    int min_s = min(v1.size(), v2.size());
    
    for (int i=0; i<min_s; ++i) {
        if (v1[i] == v2[i]) result = v1[i];
        else break;
    }
    return result;
}

int main()
{
    TreeNode n1(10), n2(20), n3(30), n4(40), n5(50), n6(60), n7(70), n8(80), n9(90);
    n1.left  = &n2;
    n1.right = &n3;
    n2.left  = &n4;
    n2.right = &n5; 
    n3.left  = &n6;
    n3.right = &n7;
    n4.left  = &n8;
    n7.right = &n9;
    
    TreeNode * shared_ancestor = nullptr;
    
    shared_ancestor = get_shared_ancestor(&n1, 80, 90);
    if ( shared_ancestor == nullptr) cout << "No shared Ancestor!\n";
    else cout << "Shared Ancestor is: " << shared_ancestor->data << endl;

    shared_ancestor = get_shared_ancestor(&n1, 40, 80);
    if ( shared_ancestor == nullptr) cout << "No shared Ancestor!\n";
    else cout << "Shared Ancestor is: " << shared_ancestor->data << endl;
    
    return 0;
}