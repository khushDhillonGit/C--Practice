#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<string>> ans;
bool isOk(vector<string> *q, int r, int c, int n)
{
  for (int i = 0; i < r; i++)
  {
    if ((*q)[i][c] == 'Q')
      return false;
  }
  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
  {
    if ((*q)[i][j] == 'Q')
      return false;
  }
  for (int i = r - 1, j = c + 1; i >= 0 && j <= n; i--, j++)
  {
    if ((*q)[i][j] == 'Q')
      return false;
  }
  return true;
}
void Recursion(vector<string> *q, int r, int n)
{
  if (n == r)
  {
    ans.push_back(*q);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (isOk(q, r, i, n))
    {
      (*q)[r][i] = 'Q';
      Recursion(q, r + 1, n);
      (*q)[r][i] = '.';
    }
  }
}
vector<vector<string>> solveNQueens(int n)
{
  vector<string> queens(n, string(n, '.'));
  Recursion(&queens, 0, n);
  return ans;
}
int main()
{
  ans = solveNQueens(8);

  for (auto a : ans)
  {
    for (auto x : a)
    {
      cout << x << " " << endl;
    }
    cout << "" << endl;
  }
}