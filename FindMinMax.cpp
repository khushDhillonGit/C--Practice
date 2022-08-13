#include <iostream>

using namespace std;

int main(){
  int a[10] = {6,5,9,8,4,7,12,11,18,3};
  int min = a[0],max = a[0];
  for(int i=0;i<10;i++){
      if(a[i] > max){
        max = a[i];
      }
      if(a[i] < min){
        min = a[i];
      }
  }   
  cout << min << " - "<< max << endl;
}
