#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int hammingWeight(uint32_t n)
{
  int count = 0;
  // my way
  //  while (n > 0)
  //  {
  //    int rem = n % 2;
  //    n /= 2;
  //    rem == 1 ? count++ : true;
  //  }
  // better way
  while (n)
  {
    n &= (n - 1);
    count++;
  }
  return count;
}
int main()
{
}