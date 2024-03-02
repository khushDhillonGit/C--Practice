#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int Recursion(int *a, int l, int r, int x)
{
  int mid = (l + r) / 2;
  if (l > r)
  {
    return -1;
  }

  if (x > a[mid])
  {
    return Recursion(a, mid + 1, r, x);
  }
  else if (x < a[mid])
  {
    return Recursion(a, l, mid - 1, x);
  }

  return mid;
}
int main()
{
  int a[] = {1, 2, 3, 4, 5};
  cout << Recursion(a, 0, 4, 4) << endl;
}