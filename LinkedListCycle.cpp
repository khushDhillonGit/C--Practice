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
ListNode *detectCycle(ListNode *head)
{
  unordered_map<ListNode *, int> a;
  ListNode *p;
  while (p)
  {
    if (a[p] == 1)
    {
      return p;
    }
    a[p] = 1;
    p = p->next;
  }
}
int main()
{
}