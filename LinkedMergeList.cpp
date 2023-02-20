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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  if (!list1)
  {
    return list2;
  }
  if (!list2)
  {
    return list1;
  }
  if (list1->val < list2->val)
  {
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
  else
  {
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
}
int main()
{
}