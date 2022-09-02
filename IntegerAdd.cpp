#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
void Recursion(vector<int> &digits, int i)
{
  if (i == -1)
  {
    return;
  }
  if (digits[i] < 9)
  {
    digits[i]++;
  }
  else
  {
    digits[i] = 0;
    if (i == 0)
    {
      digits.insert(digits.begin(), 1);
    }
    Recursion(digits, i - 1);
  }
}
vector<int> plusOne(vector<int> &digits)
{
  Recursion(digits, digits.size() - 1);
}
int main()
{
}