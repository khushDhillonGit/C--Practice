#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool valid(int r, int c, vector<vector<char>> &board)
{
  int row = r - r % 3;
  int col = c - c % 3;
  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] == board[r][c])
      return false;
  }
  for (int i = 0; i < 9; i++)
  {
    if (board[r][i] == board[r][c])
      return false;
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == board[r][c])
        return false;
    }
  }
  return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] != '.')
      {
        if (!valid(i, j, board))
        {
          return false;
        }
      }
    }
  }
  return true;
}
int main()
{
  int a = '5' - '0' - 1;
  cout << a << endl;
}