
#include <iostream>

using namespace std;

struct Rectangle //it is inside the stack frame of the memory
 {
  int length;
  int breadth;
  char a;
}r1,r2,r3; //we can declare them here too, these are global variables

//complex numbers a + ib

struct Complex
{
  int a;
  int b;
};
//Student
struct Student
{
  int roll;
  char name[25];
  char dept[10];
  char address[20];
};
//Deck of cards
struct Card{
  string face;
  const char *color;
  const char *shape;
};

void faceAssign(int index,Card *deck,const char shape[10]);
int main()
{
  // struct Rectangle r;
  // r = {5,10,"Yes"};
  // cout<< r.a<<endl;
  // struct Student s;
  // s = {12,"Khush","Science","123 kenora"};
  // cout << s.address << endl;
  struct Card deck[52];
  char x[10] = {'D','i','a','m','o','n','d','s'};
  faceAssign(0,deck,x);
  faceAssign(13,deck,"Clubs");
  faceAssign(26,deck,"Ace");
  faceAssign(39,deck,"Hearts");
  for(int i =0;i<52;i++){
    cout <<  deck[i].face << " of " << deck[i].shape << " with color " << deck[i].color << endl;
    cout <<"Working" <<endl;
  }

  
}
void faceAssign(int index,Card *deck,const char *shape){
  for(int j =0;j<13;j++){
      if((index + j) >= (index + 9)){
        deck[index + j].face = "J";
        deck[index + j + 1].face = 'Q';
        deck[index + j + 2].face = 'K';
        deck[index + j + 3].face = 'A';
      }else{
        deck[index + j].face = index + j + 2;
      }
      
      deck[index + j].shape = shape;

      if(shape == "Diamonds" || shape == "Hearts"){
        deck[index + j].color = "Red";
      }else {
        deck[index + j].color = "Black";
      }
    }
}