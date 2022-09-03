#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;
void Recursion(int st, vector<int> &k, vector<int> &nums)
{

  ans.push_back(k);

  for (int i = st; i < nums.size(); i++)
  {
    k.push_back(nums[i]);
    Recursion(i + 1, k, nums);
    k.pop_back();
  }
}
vector<vector<int>> subsets(vector<int> &nums)
{

  vector<int> k;
  ans.push_back(k);

  Recursion(0, k, nums);

  return ans;
}
int main()
{

  for (auto x : ans)
  {
    for (auto a : x)
    {
      cout << a << " " << endl;
    }
    cout << "" << endl;
  }
}