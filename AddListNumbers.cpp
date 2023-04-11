#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

struct ListNode
{
  int val;
  ListNode *next;
};
using namespace std;
// void add(int value, int *rem, ListNode **last)
// {
//   ListNode *p3;
//   int data = value;
//   data = data + *rem;
//   if (data >= 10)
//   {
//     *rem = 1;
//     data %= 10;
//   }
//   else
//   {
//     *rem = 0;
//   }
//   p3 = new ListNode;
//   p3->val = data;
//   (*last)->next = p3;
//   *last = p3;
//   (*last)->next = NULL;
// }
// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//   ListNode *last;
//   ListNode *ans = new ListNode;
//   int rem = 0;
//   ans = last;
//   add((l1->val + l2->val), &rem, &last);
//   ans = last;
//   l1 = l1->next;
//   l2 = l2->next;

//   while (l1 && l2)
//   {
//     add(l1->val + l2->val, &rem, &last);
//     l1 = l1->next;
//     l2 = l2->next;
//   }
//   while (l1)
//   {
//     add(l1->val, &rem, &last);
//     l1 = l1->next;
//   }
//   while (l2)
//   {
//     add(l2->val, &rem, &last);
//     l2 = l2->next;
//   }
//   if (rem == 1)
//   {
//     add(0, &rem, &last);
//   }
//   return ans;
// }
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  int a = 0;
  ListNode k;
  k.val = 0;
  ListNode *t = &k;
  while (a || l1 || l2)
  {
    a = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    t->next = new ListNode;
    t->next->val = a % 10;
    a /= 10;
    t = t->next;
    t->next = NULL;
    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }
  return k.next;
}
int main()
{
}