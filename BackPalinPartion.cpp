#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> res;
bool palin(int a, int b, string &k)
{
  int i = a, j = b;
  while (i < j)
  {
    if (k[i] == k[j])
    {
      i++;
      j--;
    }
    else
    {
      return false;
    }
  }
  return true;
}
void Recursion(string &s, vector<string> &k, int start)
{

  if (start == s.length())
  {
    res.push_back(k);
    return;
  }
  for (int i = start; i < s.length(); i++)
  {
    if (palin(start, i, s))
    {
      k.push_back(s.substr(start, i + 1 - start));
      Recursion(s, k, i + 1);
      k.pop_back();
    }
  }
}
// }
vector<vector<string>> partition(string s)
{
  vector<string> k;
  Recursion(s, k, 0);
  return res;
}
int main()
{

  for (auto x : res)
  {
    for (string a : x)
    {
      cout << a << endl;
    }
    cout << "line" << endl;
  }
}