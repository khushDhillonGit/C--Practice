#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
bool available(int r, int c, vector<vector<char>> &board, char val)
{
  int row = r - r % 3;
  int col = c - c % 3;

  for (int i = 0; i < 9; i++)
  {
    if (board[r][i] == val)
    {
      return false;
    }
  }
  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] == val)
    {
      return false;
    }
  }
  for (int i = row - 2; i < row + 1; i++)
  {
    for (int j = col - 2; j < col + 1; j++)
    {
      if (board[i][j] != '.')
      {
        return false;
      }
    }
  }
  return true;
}
bool Recursion(int row, int col, vector<vector<char>> &board)
{
  if (row == 9)
  {
    return true;
  }
  if (board[row][col] == '.')
  {
    for (char i = '1'; i <= '9'; i++)
    {
      if (available(row, col, board, i))
      {
        board[row][col] = i;
        col == 8 ? Recursion(row + 1, 0, board) : Recursion(row, col + 1, board);
        board[row][col] = '.';
      }
    }
  }
  else
  {
    col == 8 ? Recursion(row + 1, 0, board) : Recursion(row, col + 1, board);
  }
  return false;
}

void solveSudoku(vector<vector<char>> &board)
{
  Recursion(0, 0, board);
}
int main()
{
}