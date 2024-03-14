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


struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode* prev;
};


bool util(int index, vector<int> &nums, vector<int> &cI);
int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
{
    int m = changeIndices.size();
    int l = 0, r = m;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (util(mid, nums, changeIndices))
        {
            r = mid -1;
        }
        else
        {
            l = mid;
        }
    }
    return r == m? -1 : r;
}

bool util(int index, vector<int> &nums, vector<int> &cI)
{
    unordered_map<int, int> map;
    for (int i = 0; i <= index; i++)
    {
        // last seen of each index
        map[cI[i]] = i;
    }

    // that means at this point we havent encountered all the indexes
    if (map.size() != nums.size())
        return false;

    // to keep track if we can complete the requirement
    int count = 0;

    for (int i = 0; i <= index; i++)
    {
        if (map[cI[i]] == i)
        {
            if (count < nums[cI[i] - 1])
                return false;
            else
                count -= nums[cI[i] - 1];
        }
        else
        {
            count++;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {2,2,0};
    vector<int> cI = {2,2,2,2,3,2,2,1};
    cout << earliestSecondToMarkIndices(nums,cI) << endl;
}