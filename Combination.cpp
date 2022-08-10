#include <iostream>

using namespace std;

int Recursion(int n,int r){
  if(r == 0){
    return 1;
  }
  return Recursion(n,r-1) * (n-r+1)/r;
}

int Fac(int n){
  if(n == 0){
    return 1;
  }
  return Fac(n-1) * n;
}
int function(int n,int r){
  return Fac(n)/(Fac(n-r) * Fac(r));
}
int main(){
  cout << Recursion(5,3) << endl;
}
