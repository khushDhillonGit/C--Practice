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
int n = 0;
ListNode h(0), *l = &h;
void rec(int f)
{
  if (f == 0)
    return;
  rec(f / 10);
  int k = f;
  f -= n * 10;
  n = k;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  stack<int> s1;
  stack<int> s2;
  stack<int> f;
  ListNode *t1 = l1, *t2 = l2, h(0), *l = &h;
  while (t1)
  {
    s1.push(t1->val);
    t1 = t1->next;
  }
  while (t2)
  {
    s2.push(t2->val);
    t2 = t2->next;
  }
  int n = 0;
  while (s1.size() > 0 && s1.size())
  {
    n += ((s1.top() + s2.top()) % 10);
    f.push(n);
    s1.pop();
    s2.pop();
    n /= 10;
  }
  while (s1.size() > 0)
  {
    n += (s1.top() % 10);
    f.push(n);
    s1.pop();
    n /= 10;
  }
  while (s2.size() > 0)
  {
    n += (s2.top() % 10);
    f.push(n);
    s2.pop();
    n /= 10;
  }
  while (f.size() > 0)
  {
    ListNode *a = new ListNode(f.top());
    l->next = a;
    l = a;
    f.pop();
  }
  return h.next;
}
int main()
{
  rec(7541);
}