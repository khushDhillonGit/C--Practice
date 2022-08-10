#include <stdio.h>
int compare(int a,int b){
  if(a> b) return -1;
  else return 1;
}
void BubbleSort(int *A,int n){
  int i,j, temp;
  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
      if(compare(A[j],A[j+1]) > 0){
        temp = *(A + j);
        *(A + j)= *(A + j + 1);
        *(A + j + 1) = temp;
      }
    }

  }

}
int main(){
  int i, A[] = {2,3,4,7,8};
  BubbleSort(A,5);
  for(i= 0;i<5;i++) printf("%d ",A[i]);
}