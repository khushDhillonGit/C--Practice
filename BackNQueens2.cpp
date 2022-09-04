#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
void Recursion(int &total, vector<int> &col, vector<int> &col45, vector<int> &col135, int row, int &n)
{
  if (row == n)
  {
    total += 1;
    return;
  }
  for (int c = 0; c < n; c++)
  {
    if (col[c] && col45[row + c] && col135[n - 1 + row + c])
    {
      col[c] = col45[row + c] = col135[n - 1 + row + c] = 0;
      Recursion(total, col, col45, col135, row + 1, n);
      col[c] = col45[row + c] = col135[n - 1 + row + c] = 1;
    }
  }
}
int totalNQueens(int n)
{
  int total = 0;
  vector<int> col(n, 1), col45(2 * n - 1, 1), col135(2 * n - 1, 1);
  Recursion(total, col, col45, col135, 0, n);
  return total;
}
int main()
{
  // cout << totalNQueens
}