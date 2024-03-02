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

bool isValidBST(TreeNode *root)
{
    return isValidBSTUtil(root,INT_MAX,INT_MIN);
}

bool isValidBSTUtil(TreeNode *root, int highest, int lowest)
{
     if(root == NULL) return true;
    if(!isValidBSTUtil(root->left,root->val, lowest) || !isValidBSTUtil(root->right, highest, root->val) || root->val <= lowest || root->val >= highest) return false;
    return true;
}

int main()
{
}