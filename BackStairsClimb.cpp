#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
void Recursion(int *a, int sum, int n)
{
  static int count = 0;
  if (sum == n)
  {
    count++;
    return;
  }
  if (sum > n)
  {
    return;
  }
  for (int i = 0; i < 2; i++)
  {
    sum += a[i];
    Recursion(a, sum, n);
    sum -= a[i];
  }
}
int climbStairs(int n)
{
  int prev1 = 1, prev2 = 2;
  int c = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i = 1)
    {
      c = prev1;
    }
    else if (i = 2)
    {
      c = prev2;
    }
    else
    {
      c = prev1 + prev2;
      prev1 = prev2;
      prev2 = c;
    }
  }
  return c;
}
int main()
{
}