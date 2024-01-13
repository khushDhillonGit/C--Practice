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

int maxProduct(vector<int>& nums) {
    int min = INT_MIN;
    int prod = 1;
    int n = nums.size();

    for(int i=0;i<n; i++)
    {
        prod = prod * nums[i];
        min = max(prod,min);
        if(prod == 0) prod = 1; 
    }
    prod = 1;
    int min2 = INT_MIN;
    for(int i=n-1;i>=0; i--)
    {
        prod = prod * nums[i];
        min2 = max(prod,min2);
        if(prod == 0) prod = 1; 
    }

    return max(min,min2);
}

int main()
{
}