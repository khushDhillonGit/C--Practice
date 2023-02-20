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
ListNode *rotateRight(ListNode *head, int k)
{

  ListNode *last;
  last = head;
  int length = 0;
  while (last->next)
  {
    length++;
    last = last->next;
  }

  k %= length;
  if (k == 0)
  {
    return head;
  }
  k = length - k;
  ListNode *ptr = head;
  while (k - 1 > 0)
  {
    ptr = ptr->next;
    k--;
  }
  last->next = head;
  head = ptr->next;
  ptr->next = NULL;
  return head;
}
int main()
{
}