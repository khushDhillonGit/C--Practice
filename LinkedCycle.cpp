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
bool hasCycle(ListNode *head)
{
  ListNode *slow;
  ListNode *fast;

  while (fast && fast->next)
  {
    if (fast == slow)
    {
      return true;
    }
    fast = fast->next->next;
    slow = slow->next;
  }
  return false;
}
int main()
{
  
}