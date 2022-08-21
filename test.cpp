#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(char *a)
{
  // *(a + 1) = "D";
  // cout << *(a + 1) << endl;
  printf("%s", a);
}
int main()
{
  // int k = 9;
  // char a[10] = "Hi BRo ho";
  // char *a = "Hello";
  // char a[10] = "HELLO BRO";
  // char (*p)[10] = ;

  // cout << a << endl;
  // cout << b[0] << endl;

  // int num = 0;
  // int i;
  // for (i = 0; i < 4; ++i)
  // {
  //   cout << i << endl;
  //   ++num;
  //   cout << "Hi" << endl;
  // }
  // cout << i << endl;
  // cout << num << endl;
  // string a = "Khush";
  // char b = 'F';
  // // print(&a[0]);
  // cout << a + b << endl;
  // vector<int> p = {0};
  // p[2] = 2;
  // if (p[2] == 0)
  // {
  //   cout << p[2] << endl;
  //   cout << "Hi0" << endl;
  // }
  // else
  // {
  //   cout << "Hi" << endl;
  // }
  // cout << p[2] << endl;
  // for (int i = 0; i < 4; i++)
  // {
  //   cout << a[i] << endl;
  // }
  string a = "Jello";
  printf("%s", a.c_str());
  cout << a.length() << endl;
}