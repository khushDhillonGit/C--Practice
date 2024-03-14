#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
  bool b = false;
  bool c = false;
  if (((abs(xCenter - x2) + abs(xCenter - x1) <= 2 * radius + abs(x2 - x1)) && abs(y2 - yCenter) + abs(y1 - yCenter) == abs(y2 - y1)) || ((abs(yCenter - y1) + abs(yCenter - y2) <= 2 * radius + abs(y2 - y1)) && abs(x2 - xCenter) + abs(x1 - xCenter) == abs(x2 - x1)))
  {
    c = true;
  }
  if ((check(x1, y1, radius, xCenter, yCenter) || check(x2, y2, radius, xCenter, yCenter) || check(x1, y2, radius, xCenter, yCenter) || check(x2, y1, radius, xCenter, yCenter)))
  {
    b = true;
  }
  cout << "B is: " << b << endl;
  cout << "C is: " << c << endl;
  return b || c;
}

int main()
{

  cout << checkOverlap(1, 1, 1, -3, -3, 3, 3) << endl;
}