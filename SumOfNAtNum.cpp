#include <iostream>

using namespace std;
 
int Recursion(int m,int n){
  if(n == 0){
    return 1;
  }else{
    return Recursion(m,n-1) * m;
  }
} 

int main(){
  cout << Recursion(1,0) << endl;
}