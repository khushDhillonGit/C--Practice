#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// bool palin(int x)
// {
//   int res = 0;
//   if (x < 0 || (x != 0 && x % 10 == 0))
//   {
//     return false;
//   }
//   while (x > res)
//   {
//     res = res * 10 + x % 10;
//     x /= 10;
//   }
//   return (x == res) || (x == res / 10);
// }

// vector<long long> kthPalindrome(vector<int> &queries, int intLength)
// {
//   vector<long long> vec;
//   vector<long> p;
//   int max = queries[0];
//   for (int i = 0; i < queries.size(); i++)
//   {
//     if (queries[i] > max)
//     {
//       max = queries[i];
//     }
//   }

//   int l = intLength;
//   int digit = 1;

//   while (l > 1)
//   {
//     digit *= 10;
//     l--;
//   }

//   int num = 0;
//   int j;
//   for (j = digit; num != max && j < (digit * 10); j++)
//   {
//     if (palin(j))
//     {
//       num++;
//       p.push_back(j);
//     }
//   }
//   for (int i = 0; i < queries.size(); i++)
//   {
//     if (queries[i] <= num)
//     {
//       vec.push_back(p[queries[i] - 1]);
//     }
//     else
//     {
//       vec.push_back(-1);
//     }
//   }

//   return vec;
// }
// vector<long long> kthPalindrome(vector<int> &queries, int intLength)
// {
//   int n = (intLength % 2 == 0) ? (intLength / 2) - 1 : (intLength / 2);
//   vector<long long> res;
//   int n1 = pow(10, n);
//   for (auto a : queries)
//   {
//     string s1 = to_string(n1 + a - 1);
//     string rev = s1;
//     reverse(rev.begin(), rev.end());
//     if (intLength % 2 == 0)
//     {
//       s1 = s1 + rev;
//     }
//     else
//     {
//       s1 = s1 + rev.substr(1, rev.size() - 1);
//     }
//     if (s1.size() == intLength)
//       res.push_back(stoll(s1));
//     else
//       res.push_back(-1);
//   }
//   return res;
// }
vector<long long> kthPalindrome(vector<int> &queries, int intLength)
{
  long long power = pow(10, ((intLength + 1) / 2) - 1);
  int n = queries.size();
  vector<long long> ans(n);
  string start = "";
  for (int i = 0; i < intLength; i++)
    start += '0';
  for (int i = 0; i < n; i++)
  {
    if (queries[i] > 9 * power)
      ans[i] = -1;
    else
    {
      string s = start;
      queries[i]--;
      long long d = power;
      int k = 0;
      int st = 0, en = intLength - 1;
      while (st <= en)
      {
        st == 0 ? k = 1 : k = 0;
        s[st] = s[en] = '0' + (k + queries[i] / d);
        queries[i] %= d;
        d /= 10;
        st++, en--;
      }
      ans[i] = stoll(s);
    }
  }
  return ans;
}
int main()
{
  vector<int> q = {6, 7, 1, 900, 901};
  // vector<int> q = {1, 2, 3, 4, 5, 90};

  vector<long long> vec = kthPalindrome(q, 5);
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << endl;
  }
}