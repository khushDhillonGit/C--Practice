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

int lengthOfLIS(vector<int> &nums)
{
    vector<vector<int>> dp(2500, vector<int>(20001, -1));
    return util(nums, nums.size() - 1, 10000, dp);
}

int util(vector<int> &nums, int index, int l, vector<vector<int>> &dp)
{
    if (index < 0)
        return 0;
    if (dp[index][l + 10000] != -1)
        return dp[index][l + 10000];
    int pick = util(nums, index - 1, nums[index], dp);
    if (nums[index] < l)
        pick++;
    else
        pick = 0;
    int unpick = util(nums, index - 1, l, dp);
    dp[index][l + 10000] = pick > unpick ? pick : unpick;
    return dp[index][l + 10000];
}

int main()
{
}