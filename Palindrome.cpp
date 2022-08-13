#include <iostream>

using namespace std;

int main(){
  char a[] = "mAdaM";
  int i;
  for(i=0;a[i] != '\0';i++){

  }  
  i--;
  bool isPalindrome = true;
  for(int j=0;j<i;j++,i--){
    if(a[j]!=a[i] && (a[j] > a[i] ? a[j] + a[i] != 2*a[i] + 32:a[j] + a[i] != 2*a[j] + 32 )){
      isPalindrome = false;
      break;
    }
  }
  isPalindrome ? printf("Palindrome") : printf("Not palindrome");
}
