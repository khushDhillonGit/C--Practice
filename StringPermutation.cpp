#include <iostream>

using namespace std;

void Recursion(char *s,int k){
  static int a[4] = {0};
  static char res[4];

  int i;
  if(s[k] == '\0'){
    res[k] = '\0';
    printf("%s\n",res);
  }else{
    for(i=0;s[i] != '\0';i++){
      if(a[i] ==0){
        res[k] = s[i];
        a[i] = 1;
        Recursion(s,k+1);
        a[i] = 0;
      }
    }
  }
}
int main(){
  char a[] = "ABC";  
  Recursion(a,0);  
  
}
