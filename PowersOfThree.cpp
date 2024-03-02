#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int power(int n)
{
  int x = 0;
  while (n > 1)
  {
    n /= 3;
    x++;
  }
  return x - 1;
}
int main()
{
  cout << power(243) << endl;
}