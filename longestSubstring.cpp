#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int recursion(string s, int start, int max)
{
  string k = "";
  int count = 0;
  if (start == s.length())
  {
    return max;
  }
  for (int i = start; i < s.length(); i++)
  {
    if (k.find(s[i]) > k.length())
    {
      k += s[i];
      count++;
    }
    else
    {
      if (max < count)
      {
        max = count;
      }
      return recursion(s, start + 2, max);
    }
    if (max < count)
    {
      max = count;
    }
  }
  return max;
}
int lengthOfLongestSubstring(string s)
{
  return recursion(s, 0, 0);
}
int main()
{
  string a = "pwwkew";
  cout << lengthOfLongestSubstring(a);
  // string k = "";
  // k = a[7];
  // cout << k << endl;
}