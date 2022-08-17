#include <iostream>
#include <string>
#include <vector>
using namespace std;

// string intToRoman(int num)
// {
//   string ans = "";
//   string a[3][10] = {
//       {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
//       {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "LC"},
//       {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}};
//   while (num >= 1000)
//   {
//     ans += "M";
//     num -= 1000;
//   }
//   int temp = 100;
//   for (int i = 2; i >= 0; i--)
//   {
//     ans += a[i][num / temp];
//     num = num % temp;
//     temp /= 10;
//   }
//   return ans;
// }
bool palin(int x)
{
  int res = 0;
  if (x < 0 || (x != 0 && x % 10 == 0))
  {
    return false;
  }
  while (x > res)
  {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return (x == res) || (x == res / 10);
}

vector<long long> kthPalindrome(vector<int> &queries, int intLength)
{
  vector<long long> vec;
  for (int i = 0; i < queries.size(); i++)
  {
    int l = intLength;
    int digit = 1;
    int num = 0;
    while (l > 1)
    {
      digit *= 10;
      l--;
    }
    int j;
    for (j = digit; queries[i] != num; j++)
    {
      if (j >= (digit * 10))
      {
        vec.push_back(-1);
        break;
      }
      else
      {
        if (palin(j))
        {
          num++;
        }
      }
    }
    if (j < digit * 10)
    {
      vec.push_back(j - 1);
    }
  }
  return vec;
}

int main()
{
  vector<int> q = {1, 2, 3, 4, 5, 91};

  vector<long long> vec = kthPalindrome(q, 3);
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << endl;
  }
}
