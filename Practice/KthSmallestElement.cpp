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

int kthSmallest(TreeNode *root, int k)
{
    return smallest(root, k);
}

int smallest(TreeNode *root, int &k)
{
    if(root == NULL) return -1;
    if(k == 0) return root->val;
    int left = smallest(root->left, k);
    if(left == -1) {k--;}
    else {return left;}
    int right = smallest(root->right);
    return right;
}

int main()
{
}