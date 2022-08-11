#include <iostream>

using namespace std;
int Recursive(int *a,int l,int h,int n){

  int mid = (l+h)/2;
  if(a[mid] == n){
    return mid;
  }else if(a[mid] > n){
    return Recursive(a,l,mid-1,n);
  }
  return Recursive(a,mid+1,h,n);
}
int Binary(int *a,int length,int n){
  int l = 0,h = length-1,mid;
  while(l<=h){
    mid = (l+h)/2;
    if(a[mid] == n){
      return mid;
    }else if(a[mid] > n){
      h = mid-1;
    }else{
      l = mid+1;
    }
  }
  return -1;
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // cout << Binary(a,10,1) << endl;
    cout << Recursive(a,0,9,5) << endl;
}
