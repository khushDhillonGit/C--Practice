#include <stdio.h>
#include <cstdlib>
int main(){
  int n;
  scanf("%d",&n);
  //int a[n]; //we cant declare this array as we dont know the size of array at compilar time as it is in stack
  int *p = (int*)malloc(n*sizeof(int));
  for(int i =0;i<n;i++){
    *(p + i) = i + 1;
  }
  p = (int*)realloc(p,20*sizeof(int));
  for(int i =0;i<20;i++){
    printf("%d ",*(p+i));
  }

}