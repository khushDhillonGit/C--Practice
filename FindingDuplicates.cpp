#include <iostream>

using namespace std;
void PrintDuplicates(int *a){
  int count = 1;
  for(int i=0;i<10;i++){
    if(a[i] == a[i+1]){
      count++;
    }
    else{
      if(count > 1){
        cout << a[i] << " - "<< count<< " Times"<< endl;
      }
      count = 1;
    }
    if(i == 9)
    {
       if(count > 1){
        cout << a[i] << " - "<< count<< " Times"<< endl;
      }
    }
    
  }
}
int main(){
  int a[10] = {4,4,4,4,6,7,8,8,8,8};
  PrintDuplicates(a);
}
