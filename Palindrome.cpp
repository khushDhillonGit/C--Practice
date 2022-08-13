#include <iostream>

using namespace std;
int Recursive(char *a,int l,int h){
  if(a[l] != a[h]){
    return 0;
  }
  if(l<h){
    return Recursive(a,++l,--h);
  }else{
    return 1;
  }
  

}
int main(){
  char a[] = "nitin";
  int i;
  for(i=0;a[i] != '\0';i++){

  }  
  i--;
  Recursive(a,0,i) ? printf("Palindrome") : printf("Not Palindrome") ; 
  // bool isPalindrome = true;
  // for(int j=0;j<i;j++,i--){
  //   if(a[j]!=a[i] && (a[j] > a[i] ? a[j] + a[i] != 2*a[i] + 32:a[j] + a[i] != 2*a[j] + 32 )){
  //     isPalindrome = false;
  //     break;
  //   }
  // }
  // isPalindrome ? printf("Palindrome") : printf("Not palindrome");
}
