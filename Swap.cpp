#include <iostream>

using namespace std;

//-------passing by address -----------/
// void Swap(int *a,int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

//-----------passing by reference-----------//
//now swap is not seperate function it is a part of main function,so no function frame is created
void Swap(int &a,int &b){ //these are same variables storing the data
    int temp =a;
    a = b;
    b = temp;
}


int main(){
  int a=2,b=3;
  //Swap(&a,&b); passing by address
  Swap(a,b); //passing by Reference
  cout << "A is: " << a <<endl;
  cout << "B is: " << b <<endl;

}