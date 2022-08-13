#include <iostream>

using namespace std;

int main(){
  int a[10] = {1,3,4,5,6,8,9,11,14,15};
  int n = 10;
  int i = 0,j=9;
  
  while(i<j){
    if(a[i]+a[j] == n){
      cout << i << " " << j << endl;
      i++;
      j--;
    }else if(a[i] + a[j] > n){
      j--;
    }else{
      i++;
    }
  }
}
