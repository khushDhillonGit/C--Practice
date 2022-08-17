#include <iostream>
#include <string>
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

  int num = 0;
  int i;
  for (i = 0; 3 != num; ++i)
  {
    cout << i << endl;
    ++num;
    cout << "Fuck" << endl;
  }
  cout << i << endl;
  cout << num << endl;
  // string a = "Khush";
  // char b = 'F';
  // // print(&a[0]);
  // cout << a + b << endl;
}