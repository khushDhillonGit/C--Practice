#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string sReverse(string a, int last)
{
  static string b = "";
  if (last == a.length())
  {
    return "";
  }
  sReverse(a, last + 1);
  b += a[last];
  return b;
}
bool cPalin(string a)
{
  if (a.length() == 0 || a.length() == 1)
  {
    return true;
  }
  if (a[0] == a[a.length() - 1])
  {
    return cPalin(a.substr(1, a.length() - 2));
  }
  return false;
}
int main()
{
  // printf("%s", sReverse("Khushwinder", 0).c_str());
  cout << cPalin("KAYAK") << endl;
}