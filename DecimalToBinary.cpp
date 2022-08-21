#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
string fun(int num)
{
  static string a = "0";
  if (num == 0)
  {
    return a;
  }
  fun(num / 2);
  a += '0' + (num % 2);
  return a;
}

int main()
{
  cout << fun(102458) << endl;
}