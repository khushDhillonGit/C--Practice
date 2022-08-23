#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
bool squareIsWhite(string coordinates)
{
  int a = coordinates[0] - 97;
  int b = coordinates[1] - '1';
  if ((a + b) % 2 == 0)
  {
    return false;
  }
  return true;
}
int main()
{
}