#include <iostream>

using namespace std;
struct Array{
  int A[10];
  int size;
  int length;
};

int Delete(struct Array *a,int index){
  if(index >=0 && index <a->length){

      int element = a->A[index];
      for(int i = index;i<a->length-1;i++){
        a->A[i] = a->A[i+1];
      }
      a->A[a->length-1] = 0;
      a->length--;
      return element;
  }
  return -1;
}
void Display(struct Array a){
  for (int i = 0; i < a.length; i++)
  {
    printf("%d\n",a.A[i]);
  }
}
void Insert(struct Array *a,int index,int element){
  if(index >=0 && index <= a->length){
    for (int i = a->length; i > index; i--)
    {
      a->A[i] = a->A[i-1]; 
    }
    a->A[index] = element;
    a->length++;
  }else{
    a->A[index] = element;
  }
}

void Append(struct Array *a,int x){
  if(a->length<a->size)
    a->A[a->length++] = x;
}

int main(){
  struct Array a ={{1,2,3,4,5,6,7},10,7};
  int length = 7;//as it has only four elements
  //size of a is 10 and length is 4;


  //----------All operations that can be formed on array
  //1 --Display
  // Display(a);

  //2 -- Add element at end
  // Apppend(&a,5);
  

  //3 -Insert element at index
  // Insert(&a,8,4);
  // Display(a);
  
  //4 --Delete
  Delete(&a,1);
  Display(a);

}
