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

int maxFrequencyElements(vector<int> &nums)
{
    int max = 1;
    int total = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        int curr = 0;
        while (i < nums.size() && nums[i] == ele)
        {
            curr++;
            i++;
        }

        if (curr > max)
        {
            total = 0;
            max = curr;
        }

        if (curr == max)
        {
            total += curr;
        }
        i--;
    }

    return total;
}

int main()
{
}