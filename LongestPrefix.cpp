#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
  string ans = "";
  char a;
  for (int j = 0; j < strs[0].length(); j++)
  {
    a = strs[0][j];
    for (int i = 1; i < strs.size(); i++)
    {
      if (strs[i][j] != i)
      {
        return ans;
      }
    }
    ans += a;
  }
  return ans;
}
int main()
{
}