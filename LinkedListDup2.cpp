#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
};
ListNode *deleteDuplicates(ListNode *head)
{
  if (!head || !head->next)
  {
    return head;
  }
  int val = head->val;
  ListNode *p;
  p = head->next;
  if (p->val == val)
  {
    while (p && p->val == val)
    {
      p = p->next;
    }
    return deleteDuplicates(p);
  }
  else
  {
    head->next = deleteDuplicates(p);
    return head;
  }
}
int main()
{
}