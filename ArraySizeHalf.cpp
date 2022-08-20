#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

int minSetSize(vector<int> &arr)
{

  int max = arr[0];
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }

  vector<int> v((max + 1), 0);

  for (int i = 0; i < arr.size(); i++)
  {
    v[arr[i]] = v[arr[i]] + 1;
  }

  int k = 0, n = 0;
  sort(v.begin(), v.end());

  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (k >= arr.size() / 2)
    {
      return n;
    }
    n++;
    k += v[i];
  }
  return -1;
}
int main()
{
  vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
  cout << minSetSize(arr) << endl;
}
