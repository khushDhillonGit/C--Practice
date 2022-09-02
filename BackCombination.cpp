#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> final;
unordered_map<vector<int>, int> k;
void Recursion(vector<int> &candidates, int target, vector<int> ans, int start)
{
  if (target == 0)
  {
    sort(ans.begin(), ans.end());
    final.push_back(ans);
    return;
  }
  if (target < 0)
  {
    return;
  }
  for (int i = start; i < candidates.size(); i++)
  {
    if (candidates[i] <= target)
    {
      target -= candidates[i];
      ans.push_back(candidates[i]);
      Recursion(candidates, target, ans, i + 1);
      ans.pop_back();
      target += candidates[i];
    }
  }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
}
int main()
{
}