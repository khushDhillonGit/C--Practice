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
vector<string> findRepeatedDnaSequences(string s)
{
  unordered_map<int, int> m;
  vector<string> r;
  int t = 0, i = 0, ss = s.size();
  while (i < 9)
    t = t << 3 | s[i++] & 7;
  while (i < ss)
    if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
      r.push_back(s.substr(i - 10, 10));
  return r;
}
int main()
{
  vector<string> a = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  for (string k : a)
  {
    cout << k << endl;
  }
}