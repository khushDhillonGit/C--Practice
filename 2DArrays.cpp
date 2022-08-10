#include <iostream>

using namespace std;

int main(){
  // //In stack
  // int a[2][3] = {{1,2,3},{4,5,6}};  

  // //-------------Heap----------------//
  // //this array is declared in stack
  // int *p[2];
  // //these arrays are in heap
  // p[0] = new int[3];
  // p[1] = new int [4];

  // p[0][0] = 1;
  // p[0][1] = 1;
  // p[0][2] = 1;

  // p[1][0] = 1;
  // p[1][1] = 1;
  // p[1][2] = 1;
  // p[1][3] = 1;
  
  // //this double pointer variable is declared in stack
  // int **k;

  // // the array of pinters is declared in heap
  // k = new int*[2];

  // //these connecting arrays also declared in heap
  // k[0] = new int[3];
  // k[1] = new int[4];

  // int b[3] = {0};
  // k[0] = b;

  // k[1][0] = 1;
  // k[1][1] = 1;
  // k[1][2] = 1;
  // k[1][3] = 1;

  int **p;
  int *a[3];
  p = a;

}
