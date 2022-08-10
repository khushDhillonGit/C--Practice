#include <iostream>
using namespace std;
void printCrap(char *a);

struct Rectangle //it is inside the stack frame of the memory
{
  int length[2];
  int breadth;
  char a;
};
int main(){
  // struct Rectangle r;
  // r.length = 5;
  // r.breadth = 10;
  // r.a = 'A';
  // cout << r.a << endl;

  // char a[6] = {'h','e','l'};
  // cout << a << endl;
  // cout << r.length[0] << endl;
  
  //correct
  // const char *a = "Hello";
  //printCrap(a); 

  //correct
  //string a = "Hello";//string a is also a pointer
  //printCrap(&a[0]);//passing address of first letter of string will do the job

  //correct
  //char a[4] = "Hel"; //this is not stored as constant
  //printCrap(a); 

  //printCrap("Hel"); //but this is passing of a constant, so use const char*a pointer
}

void printCrap(char *a){

  *(a+1) = '2';
  cout << *(a+1) << endl;

}