#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

bool check(int x, int y, int r, int xC, int yC)
{
  if ((xC - x) * (xC - x) + (yC - y) * (yC - y) - r * r <= 0)
  {
    cout << "Point: " << x << " " << y << endl;
    return true;
  }
  return false;
}
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
{
  int l = abs(x2 - x1);
  int w = abs(y2 - y1);
  bool a = false;
  bool b = false;
  bool c = false;
  bool d = false;
  if (abs(x2 - xCenter) + abs(x1 - xCenter) == l && abs(y2 - yCenter) + abs(y1 - yCenter) == w)
  {
    d = true;
  }
  if (((abs(xCenter - x2) <= radius || abs(xCenter - x1) <= radius) && abs(y2 - yCenter) + abs(y1 - yCenter) == w) || ((abs(yCenter - y1) <= radius || abs(yCenter - y2) <= radius) && abs(x2 - xCenter) + abs(x1 - xCenter) == l))
  {
    c = true;
  }
  if ((abs(x1 - xCenter) + abs(x2 - xCenter) == 2 * radius + l) && (abs(y1 - yCenter) + abs(y2 - yCenter) == 2 * radius + w))
  {
    a = true;
  }
  if ((check(x1, y1, radius, xCenter, yCenter) || check(x2, y2, radius, xCenter, yCenter) || check(x1, y2, radius, xCenter, yCenter) || check(x2, y1, radius, xCenter, yCenter)))
  {
    b = true;
  }
  cout << "A is: " << a << endl;
  cout << "B is: " << b << endl;
  cout << "C is: " << c << endl;
  cout << "D is: " << d << endl;
  return a || b || c || d;
}

int main()
{

  cout << checkOverlap(2, 3, 1, 0, 6, 1, 10) << endl;
}