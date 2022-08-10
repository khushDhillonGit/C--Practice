#include <iostream>

using namespace std;
int Fac(int n);
int Pow(int m,int n);
//my o(n) method
double Recursion(int x,int n){
  static int a = n;
  if(1== n){
    return 1;
  }
  return Recursion(x,n-1) * (x/(double)(a - n +1)) + 1;
}
//Teacher o(n) method
double Recursion(int x,int n){
  static int a = 1;
  if(1== n){
    return 1;
  }
  a = 1 + x/(double)n *a;
  return Recursion(x,n-1);
}
//o(n^2)
// double Recursion(int x,int n){
//   static int a = 1;
//   static int b = 1;
//   if(n == 1){
//     return 1;
//   }else{
//     //return Recursion(x,n-1) + (Pow(x,n-1))/(double)Fac(n-1);
//     double r = Recursion(x,n-1);
//     a = a*x;
//     b = b*(n-1);
//     return r + a/(double)b;
//   }
// }

int Fac(int n){
  if(n == 0){
    return 1;
  }else{
    return Fac(n-1) * n;
  }
}
int Pow(int m,int n){
  if(n ==0){
    return 1;
  }else{
    return Pow(m,n-1)*m;
  }
}

int main(){  
  cout << Recursion(2,4) << endl;
}