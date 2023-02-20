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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
  unordered_map<int,int> k;
  if (!head || !head->next)
  {
    return head;
  }
  ListNode *p = head, *n, *h = NULL;
  int count = 0;
  while (p)
  {
    count++;
    if (count == left)
    {
      while (count <= right && p)
      {
        n = p->next;
        p->next = h->next;
        h->next = p;
        p = n;
        count++;
      }
    }
    else
    {
      p = p->next;
    }
  }
  return head;
}
int main()
{
}