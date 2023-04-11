#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int Recursion(int n, int count)
{
  if (n == 1)
  {
    return count;
  }
  if (n % 2 == 0)
  {
    return Recursion(n / 2, count + 1);
  }
  else
  {
    int a = Recursion(n + 1, count + 1);
    int b = Recursion(n - 1, count + 1);
    return a < b ? a : b;
  }
}
int integerReplacement(int n)
{
  return Recursion(n, 0);
}
int main()
{
  cout << integerReplacement(13) << endl;
}