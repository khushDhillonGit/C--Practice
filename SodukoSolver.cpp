#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
void removeInBox(vector<vector<char>> &board, vector<char> &k, int r, int c);
vector<char> available(int r, int c, vector<vector<char>> &board)
{
  vector<char> k = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 9; i++)
  {
    if (board[r][i] != '.')
    {
      k.erase(remove(k.begin(), k.end(), board[r][i]), k.end());
    }
  }
  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] != '.')
    {
      k.erase(remove(k.begin(), k.end(), board[i][c]), k.end());
    }
  }

  removeInBox(board, k, r, c);
  return k;
}
void removeInBox(vector<vector<char>> &board, vector<char> &k, int r, int c)
{
  int row = 0;
  int col = 0;
  bool found = false;
  for (int i = 2; i < 9; i += 3)
  {
    for (int j = 2; j < 9; j += 3)
    {
      if (r <= i && c <= j)
      {

        row = i;
        col = j;
        found = true;
        break;
      }
    }
    if (found)
    {
      break;
    }
  }

  for (int i = row - 2; i < row + 1; i++)
  {
    for (int j = col - 2; j < col + 1; j++)
    {
      if (board[i][j] != '.')
      {
        k.erase(remove(k.begin(), k.end(), board[i][j]), k.end());
      }
    }
  }
}
void Recursion(int row, int col, vector<vector<char>> &board, vector<vector<char>> &board0)
{
  if (row == 9)
  {
    board = board0;
    return;
  }
  if (board0[row][col] == '.')
  {
    vector<char> Available;
    Available = available(row, col, board0);
    if (Available.size() == 0)
    {
      return;
    }
    for (int j = 0; j < Available.size(); j++)
    {
      board0[row][col] = Available[j];
      col == 8 ? Recursion(row + 1, 0, board, board0) : Recursion(row, col + 1, board, board0);
      board0[row][col] = '.';
    }
  }
  else
  {
    col == 8 ? Recursion(row + 1, 0, board, board0) : Recursion(row, col + 1, board, board0);
  }
}

void solveSudoku(vector<vector<char>> &board)
{
  vector<vector<char>> board0 = board;
  Recursion(0, 0, board, board0);
}
int main()
{
}