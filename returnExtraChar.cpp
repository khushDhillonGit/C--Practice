#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
char findTheDifference(string s, string t)
{
  int res = 0;
  for (char x : s)
  {
    res ^= x;
  }
  for (char x : t)
  {
    res ^= x;
  }
  return (char)res;
}
int main()
{
  cout << findTheDifference("abcd", "cadbh") << endl;
}