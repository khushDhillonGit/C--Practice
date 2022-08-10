#include <stdio.h>
int* Add(int* a,int* b);
int main(){
  // int a,b;
  // a = 2; b = 4;
  // int *c = Add(&a,&b);
  
  // printf("%d",*c);
  // free(c);

  // return 0;
  char *c = "Hello World";
  printf("%s",*c);
}
// int* Add(int* a,int* b){
//     int *c = (int*)malloc(sizeof(int));
//     *c = *a + *b;
//     return c;
// }