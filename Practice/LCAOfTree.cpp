#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    FindElement(root,p,pathP);
    FindElement(root,q,pathQ);

    int i = 1;
    while(pathP[i] == pathQ[i])
    {
        i++;
    }

    return pathP[--i];

}

bool FindElement(TreeNode *root, TreeNode *node, vector<TreeNode*> &result)
{
    if (root == nullptr) return false; 
    if(root == node) return true;
    result.push_back(root);

    if(FindElement(root->left,node,result)) return true;
    if(FindElement(root->right,node,result)) return true;
    result.pop_back();
    return false;
}
int main()
{
}