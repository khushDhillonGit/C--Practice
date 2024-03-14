#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void merge(int *a, int s, int e)
{
  int *t = (int *)malloc((e - s + 1) * sizeof(int));
  int mid = (s + e) / 2;
  int i = s, j = mid + 1, k = 0;
  while (i <= mid && j <= e)
  {
    if (a[i] >= a[j])
    {
      t[k++] = a[j++];
    }
    else
    {
      t[k++] = a[i++];
    }
  }
  while (i <= mid)
  {
    t[k++] = a[i++];
  }
  while (j <= e)
  {
    t[k++] = a[j++];
  }
  for (int i = s; i <= e; i++)
  {
    a[i] = t[i - s];
  }
}
void MergeSort(int *a, int s, int e)
{
  if (s < e)
  {
    int mid = (s + e) / 2;
    MergeSort(a, s, mid);
    MergeSort(a, mid + 1, e);
    merge(a, s, e);
  }
}
int main()
{
  int a[] = {6, 5, 4, 3, 2, 1};
  for (int x : a)
  {
    cout << x << " ";
  }
  cout << "" << endl;
  MergeSort(a, 0, 5);
  for (int x : a)
  {
    cout << x << " ";
  }
}