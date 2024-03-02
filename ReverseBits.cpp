#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
  // uint32_t a = 0;
  // while (n != 0)
  // {
  //   int rem = n % 2;
  //   n /= 2;
  //   if (rem == 1)
  //   {
  //     a = a << 1;
  //     a += 1;
  //   }
  //   else
  //   {
  //     a = a << 1;
  //   }
  // }
  // for (int i = 1; i <= 32; i++)
  // {
  // }
  uint32_t k = 2147483648;
  uint32_t f = 0;
  for (int i = 0; i <= 31; i++)
  {
    k = k >> i;
    if ((n & k) != 0)
    {
      f += pow(2, i);
    }
    k = 2147483648;
  }
  return f;
}
int main()
{
  // int n = 9;
  // n = n >> 1;
  // cout << n << endl;
  cout << reverseBits(43261596);
}