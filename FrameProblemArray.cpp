#include <iostream>

using namespace std;

int * Array(int size){
    int *p = (int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
      *(p+i) = i+1;
    }  
    return p;
}

int main(){
  int *p = Array(5);
  int *k;
  k = 0;
  *k = 5;
  for(int i=0;i<5;i++){
    cout << *(p+i) << " " ;
  }

}