#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string Recursion(string a, int last)
{
  static string b = "";
  if (last == a.length())
  {
    return "";
  }
  Recursion(a, last + 1);
  b += a[last];
  return b;
}
int main()
{
  printf("%s", Recursion("Khushwinder", 0).c_str());
}