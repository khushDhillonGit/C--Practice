#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> fallingSquares(vector<vector<int>> &positions)
{
  vector<int> ans;
  int fL = positions[0][0];
  int fR = positions[0][0] + positions[0][1];
  int fH = positions[0][1];
  ans.push_back(fH);
  for (int i = 1; i < positions.size(); i++)
  {
    int l = positions[i][0];
    int r = positions[i][0] + positions[i][1];
    int h = positions[i][1];
    if (r >= fL && r < fR || l >= fL && l < fR)
    {
      ans.push_back(h + ans.back());
        }
    int fL = positions[i][0] + positions[i][1];
    int cH = positions[i][1];
  }
}
int main()
{
}