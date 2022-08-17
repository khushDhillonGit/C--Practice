#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> vec;
  vector<int>::iterator a = vec.begin();
  for (int i = 0; i < 4; i++)
  {
    vec.push_back(i);
  }
  for (int i = 0; i < 4; i++)
  {
    vec[i];
  }
  return 0;
}
