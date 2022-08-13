#include <iostream>

using namespace std;

int main(){
  char a[] = "khush";
  char b[] = "ksuh";
  int x=0,s=0;
  for(int i=0;a[i] != '\0' ;i++){
    x = 1;
    x = x<<(a[i] - 97);
    s=x|s;
  }

  for(int i=0;b[i] != '\0' ;i++){
    x = 1;
    x = x <<(b[i]-97);
    if((x&s)==0){
      cout << "Not anagrams" << endl;
      break;
    }
  }
}  
