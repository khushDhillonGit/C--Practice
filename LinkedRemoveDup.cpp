#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
};
ListNode *deleteDuplicates(ListNode *head)
{
  ListNode *p;
  ListNode *q = NULL;
  p = head;
  while (p)
  {
    if (p->val == q->val)
    {
      q->next = p->next;
      p = p->next;
    }
    else
    {
      q = p;
      p = p->next;
    }
  }
  return head;
}
int main()
{
}