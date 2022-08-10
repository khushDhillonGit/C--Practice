#include <iostream>

using namespace std;

int main(){
  int a = 10;
  int &r = a; // refernce must be initialised

  int b = 20;
  r = b; //means now a and r are 20
  
  return 0;

}