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
ListNode *h;
bool palin = true;
void Recursion(ListNode *head)
{
  if (!head)
  {
    return;
  }
  Recursion(head->next);
  if (h->val != head->val)
  {
    palin = false;
    return;
  }
  h = h->next;
}
bool isPalindrome(ListNode *head)
{
  h = head;
  Recursion(head);
  return palin;
}
int main()
{
}