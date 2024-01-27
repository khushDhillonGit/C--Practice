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

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(101, -1);
    return util(nums, n - 1, dp);
}

int util(vector<int> &nums, int index, vector<int> &dp)
{
    if (index < 0)
        return 0;

    int n = dp[index];
    if (n != -1)
        return n;

    int robed = nums[index] + util(nums, index - 2, dp);
    int notRobed = util(nums, index - 1, dp);

    dp[index] = max(robed, notRobed);
    return dp[index];
}

int main()
{
    
}