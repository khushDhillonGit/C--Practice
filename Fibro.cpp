#include <iostream>

using namespace std;
int Recursion(int n){
  static int b = 0;
  if(n == 1){
    return 0;
  }else if(n == 2){
    return 1;
  }
  // int k = Recursion(n-1);
  // int r = k + b;
  // b = k;
  // return r;
   
  int r = Recursion(n-1) + b;
  b = Recursion(n-1);
return r;
  // return Recursion(n-1) + Recursion(n-2);
}

int main(){
  cout << Recursion(45) << endl;
}