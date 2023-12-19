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

TreeNode *sUtil(int l, int r, vector<int> &nums)
{
    if (l > r)
        return NULL;
    int size = nums.size();
    int m = (l + r) / 2;

    TreeNode *root = new TreeNode(nums[m]);

    root->left = sUtil(l, m - 1, nums);
    root->right = sUtil(m + 1, r, nums);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return sUtil(0, nums.size() - 1, nums);
}

int main()
{
}