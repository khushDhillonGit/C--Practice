#include <iostream>

using namespace std;

int Recursion(int n){
  if(n > 0){
    return Recursion(n-1) + n;
  }
  return 0;
}

int main(){
  int a = 5;
  cout << Recursion(a) << endl;
}