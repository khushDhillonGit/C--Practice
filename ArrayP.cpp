#include <iostream>

using namespace std;
void swap(int *a,int i,int j){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void AddMissing(int *a,int n,int *l){
  a[(*l)++] = n;
  for(int i=(*l)-2;i>=0;i--){
    if(a[i]>a[i+1]){
      swap(a,i,i+1);
    }
  }
}
int main(){
    int a[10] = {2,3,5,6,10,11};
    int length = 6;
    int con = a[0];
    for(int i=0;i<10;i++){

      if(a[i] != con){
        cout<< con<< " ";
        AddMissing(a,con,&length);
      }
      con++;
    }
    cout<<endl;
   for(int k:a){
         cout << k <<endl;
    }
}
