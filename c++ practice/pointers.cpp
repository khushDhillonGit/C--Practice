// Boiler plate for c++ competative
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int val)
  {
    val = val;
    next = NULL;
  }
};

int main()
{
    // int a = 5;
    // int *p = &a;

    // printf("%d\n",a);
    // printf("%d\n",p);
    // printf("%d\n",*p);
    
    int a[2][3] = {{1,2,3},{4,5,6}};

    //int **p = a; //this will give an error

    int (*p)[3] = a;

  //These all have same value
    printf("%d\n",a);
    printf("%d\n",&a);
    printf("%d\n",*a);
    printf("%d\n",&a[0]);
    printf("%d\n",a[0]);
    printf("%d\n",&a[0][0]);

    int c[3][2][2];
    int (*q)[2][2] = c;
    // int *p[3] = a;  

    // (*p)[3] is a pointer pointing at array of 3 elements and *p[3] is a pointer array having length three



}