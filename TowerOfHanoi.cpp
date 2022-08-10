#include <iostream>

using namespace std;

void Recursion(int n,char A,char B,char C){
    if(n > 0){
      Recursion(n-1,A,C,B);
      printf(" disk number %d from %c to %c\n",n,A,C);
      
      Recursion(n-1,B,A,C);
    }
}
int main(){
  char A = 'A',B='B',C ='C';
  Recursion(16,A,B,C);
}
