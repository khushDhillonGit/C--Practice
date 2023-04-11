#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<int> res;
void Recursion(bitset<32> &k, vector<int> &ans, int n)
{
  if (n == 0)
  {
    ans.push_back(k.to_ulong());
    return;
  }
  else
  {
    Recursion(k, ans, n - 1);
    k.flip(n - 1);
    Recursion(k, ans, n - 1);
  }
}
vector<int> grayCode(int n)
{
  bitset<32> k;
  vector<int> ans;
  Recursion(k, ans, n);
  return ans;
}
int main()
{
  vector<int> ans = grayCode(2);
  for (int x : ans)
  {
    cout << x << endl;
  }
}
