#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector<string> ans;
vector<string> values = {"", "", {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
void perm(string digits, int digit, int e)
{
  static string k = "";
  if (e == digits.length())
  {
    ans.push_back(k);
    return;
  }
  for (int i = 0; values[(digit)][i] != '\0'; i++)
  {
    k += values[digit][i];
    perm(digits, digits[e + 1] - '0', e + 1);
    k = k.substr(0, k.length() - 1);
  }
}

vector<string> letterCombinations(string digits)
{
  perm(digits, digits[0] - '0', 0);
  return ans;
}

int main()
{
  vector<string> ans = letterCombinations("239");
  for (string x : ans)
  {
    cout << x << endl;
  }
}