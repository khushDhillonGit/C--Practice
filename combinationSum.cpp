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

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> curr;
    util(candidates,candidates.size()-1,target,res,curr);
    return res;
}

void util(vector<int>& nums, int index, int target, vector<vector<int>> &res, vector<int> &curr)
{
    if(index < 0 || target < 0) return;

    if(target == 0){
            res.push_back(curr);
            return;
    }

    curr.push_back(nums[index]);
    util(nums,index,target - nums[index],res,curr);
    curr.pop_back(); 
    util(nums,index -1,target,res,curr);
    return;    
}

int main()
{
}