#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
long long recursion(long long needed)
{
  static long long n = 1;
  static long long Totalapples = 0;

  if (Totalapples >= needed)
  {
    return n;
  }
  n++;
  if (n % 2 == 0)
  {
    Totalapples += 3 * n * n;
  }

  return recursion(needed);
}
long long minimumPerimeter(long long neededApples)
{
  return recursion(neededApples) * 4;
}
int main()
{
  cout << minimumPerimeter(800) << endl;
}