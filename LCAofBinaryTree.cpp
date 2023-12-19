#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
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

}

bool FindElement(TreeNode *root, vector<TreeNode*> &path)
{
    if(root == NULL) return false;
    if(root->val == )
    path.push_back(root);
    if(FindElement(root->left))
    {
        return true;
    }else
    {
        path.pop_back();
        FindElement(root->right);
    } 
}
int main()
{

}