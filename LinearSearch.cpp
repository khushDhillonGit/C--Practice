#include <iostream>

using namespace std;

int linear(int *a,int n,int length){
  for(int i=0;i<length;i++){
    if(a[i] == n){
      //--- This is to make linear search more efficient this method is called transposition --////
      int temp = a[i-1];
      a[i-1] = a[i];
      a[i] = temp;
      return i-1;
    }
  }
  return -1;
}
int main(){
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  cout << linear(a,5,10) << endl;
}
