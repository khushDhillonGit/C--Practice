#include <iostream>

using namespace std;

struct Rectangle{
  int len;
  int bre;
};

int main(){
  struct Rectangle r = {10,15};
  struct Rectangle *p;
  // (*p).len;
  // *p->len;
  // p = new struct Rectangle;
  //or
  p = (struct Rectangle*)malloc(sizeof(struct Rectangle));
  p = &r;
  
  return 0;

}