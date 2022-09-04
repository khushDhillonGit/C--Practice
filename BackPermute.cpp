#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;
void Recursion(vector<int> &nums, int l, int r)
{
  if (l == r)
  {
    ans.push_back(nums);
    return;
  }
  for (int i = l; i < r; i++)
  {
    if (nums[i] == nums[l])
      continue;
    swap(nums[i], nums[l]);
    Recursion(nums, l + 1, r);
    swap(nums[i], nums[l]);
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  Recursion(nums, 0, nums.size());
  return ans;
}
int main()
{
}