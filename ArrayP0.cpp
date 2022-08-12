#include <iostream>

using namespace std;

int main(){
  int a[10] = {13,4,5,2,6,7,9,10,16,14};
  int l = 16;
  int s =1;
  int b[l] = {0};
  for(int i=0;i<10;i++){
    b[a[i]-1]++;
  }
  for(int i=0;i<l;i++){
    if(b[i] == 0){
      cout << i+1 << endl;
    }
  }  
}
