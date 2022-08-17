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

  string a = "Khush";
  char b = 'F';
  // print(&a[0]);
  cout << a + b << endl;
}