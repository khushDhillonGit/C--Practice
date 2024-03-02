#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int formula(int sf, int sk, int sFuel, int dis)
{
  return sf - sk + dis + sFuel;
}

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
  int disCovered = 0;
  int scount = 0;
  if (startFuel >= target)
  {
    return 0;
  }
  for (int i = 0; i < stations.size(); i++)
  {

    if (startFuel < stations[i][0] - disCovered)
    {
      return -1;
    }

    if ((startFuel >= (stations[i][0] - disCovered) && startFuel < (stations[i + 1][0] - disCovered)) || (i == stations.size() - 1 && startFuel >= stations[i][0] - disCovered))
    {
      startFuel = startFuel - (stations[i][0] - disCovered) + stations[i][1];
      disCovered = stations[i][0];
      scount++;
    }

    if (target - disCovered <= startFuel)
    {
      return scount;
    }
  }
  return -1;
}

int main()
{
  vector<vector<int>> a = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  // target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
  cout << minRefuelStops(100, 10, a) << endl;
}