#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void utils(int k)
{
  if (k == 0)
  {
    return;
  }
  else
  {
    utils(k - 1);
    cout << k << endl;
    utils(k - 1);
  }
}
int main()
{

  utils(3);
}