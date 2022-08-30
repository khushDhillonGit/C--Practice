#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int minimumDeletions(string s)
{
  int a = 0, b = 0, n = s.length();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a')
    {
      a++;
    }
  }
  int del = a;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a')
    {
      a--;
    }
    else
    {
      b++;
    }
    del = min(del, a + b);
  }
  return del;
}
int main()
{
}