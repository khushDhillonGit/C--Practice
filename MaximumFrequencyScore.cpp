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

int totalCost(vector<int> &nums, int mid, long long k)
{
    int cost = 1;
    int size = nums.size();

    int i = mid - 1, j = mid + 1;

    while ((i > -1 || j < size))
    {
        if (i == -1 && j != size)
        {
            while (nums[j] != nums[mid] && k > 0)
            {
                nums[j]--;
                k--;
            }

            if (nums[j] == nums[mid])
            {
                cost++;
            }

            j++;
        }

        else if (i != -1 && j == size)
        {
            while (nums[i] != nums[mid] && k > 0)
            {
                nums[i]++;
                k--;
            }

            if (nums[i] == nums[mid])
            {
                cost++;
            }

            i--;
        }
        else
        {
            if ((nums[mid] - nums[i]) < nums[j] - nums[mid])
            {
                while (nums[i] != nums[mid] && k > 0)
                {
                    nums[i]++;
                    k--;
                }

                if (nums[i] == nums[mid])
                {
                    cost++;
                }

                i--;
            }
            else
            {
                while (nums[j] != nums[mid] && k > 0)
                {
                    nums[j]--;
                    k--;
                }

                if (nums[j] == nums[mid])
                {
                    cost++;
                }

                j++;
            }
        }
    }

    return cost;
}

int maxFrequencyScore(vector<int> &nums, long long k)
{

    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    std::vector<int> diffs(size + 1);
    diffs[0] = 0;

    for (int i = 1; i < size; i++)
    {
        diffs[i] = nums[i] - nums[i - 1];
    }



        int i =0,j=0,ans=0;
        while(j<size+1){
            k -= diffs[j++];
            while(k <= 0 && i<=j){
                k += diffs[i++];
                ans > j-i? ans = ans : ans = j -i;
            }
        }
        return ans;


  
}

int main()
{
    vector<int> res = {27, 8, 30, 3, 13, 28, 7, 14, 21, 19, 24, 28, 29, 1, 14, 22, 6};
    // std::sort(res.begin(), res.end());
    // vector<int> res1(res.size());
    // res1[0] = res[0];
    // for (int i = 1; i < res.size(); i++)
    // {
    //     res1[i] = res[i] - res[i - 1];
    // }
    cout << "The maximum frequency score is: " << maxFrequencyScore(res,23) << endl;
}