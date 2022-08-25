#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

void back(int *a, int l, int t);
void process(int *a);
vector<string> readBinaryWatch(int turnedOn)
{
  int a[10] = {0};
  back(a, 0, turnedOn);
  sort(ans.begin(), ans.end());
  return ans;
}
void process(int *a)
{
  int h = 0, m = 0;
  for (int i = 0; i < 10; i++)
  {
    if (a[i] == 1)
    {
      if (i < 4)
      {
        h += pow(2, i);
      }
      else
      {
        m += pow(2, i - 4);
      }
    }
  }
  if (h != 0 || m != 0)
  {
    if (h < 12 && m <= 60)
    {
      string k = "";
      k = to_string(h) + ':' + (m / 10 == 0 ? '0' + to_string(m) : to_string(m));
      ans.push_back(k);
    }
  }
}
void back(int *a, int l, int t)
{
  if (t == 0)
  {
    process(a);

    return;
  }
  for (int i = l; i < 4; i++)
  {
    if (a[i] == 0)
    {
      a[i] = 1;
      back(a, i + 1, t - 1);
      a[i] = 0;
    }
  }
}
int main()
{
  vector<string> a = readBinaryWatch(3);
  for (string x : ans)
  {
    cout << x << endl;
  }
}