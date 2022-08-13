#include <iostream>

using namespace std;

void Reverse(char *a,int l){
  for(int i=0;i<l/2;i++){
    char temp = a[i];
    a[i] = a[l-i-1];
    a[l-i-1] = temp;
  }
}
int main(){
  char a[] = "Python";
  int l = 6;
  Reverse(a,l);
  for(int i=0;a[i] != '\0';i++){
    cout << a[i] << endl;
  }
}
