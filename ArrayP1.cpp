#include <iostream>

using namespace std;

int* Function(int *a,int l,int n){
  int b[l+1] = {0};
  int *p = (int*)malloc(sizeof(int)*2);
  for(int i=0;i<10;i++){
    if(a[i] <= 10){
      if(b[n-a[i]] > 0){
        *(p+1) = i;
        *(p) = b[n-a[i]+1];
        break;
      }
      b[a[i]] = i+1;
    }
  }
    return p;
}

int main(){
  int a[10] = {6,5,9,8,4,7,12,11,18,3};
  int n = 10;
  int *p = Function(a,10,n);  
  cout << *(p) << endl;
  cout << *(p+1) << endl;
}
