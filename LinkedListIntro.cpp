#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
struct Node
{
  int data;
  struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int *a, int n, struct Node **f)
{
  int i;
  struct Node *t, *last;
  *f = (struct Node *)malloc(sizeof(struct Node));
  (*f)->data = a[0];
  (*f)->next = NULL;
  last = *f;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
void ReverseDisplay(struct Node *f)
{
  if (f)
  {
    ReverseDisplay(f->next);
    cout << f->data << endl;
  }
}
void Insert(int x, int pos)
{
  struct Node *t = new Node;
  t->data = x;
  if (pos == 0)
  {
    t->next = first;
    first = t;
  }
  else if (pos > 0)
  {
    struct Node *p = first;
    while (pos > 1 && p)
    {
      p = p->next;
      pos -= 1;
    }
    t->next = p->next;
    p->next = t;
  }
}
int Delete(int pos)
{
  struct Node *p = first;
  int x = 0;
  if (pos == 1)
  {
    first = first->next;
    x = p->data;
    delete p;
  }
  if (pos > 1)
  {
    struct Node *q = NULL;
    while (pos > 1 && p)
    {
      q = p;
      p = p->next;
      pos -= 1;
    }
    q->next = p->next;
    x = p->data;
    delete p;
  }
  return x;
}

void Display(struct Node *f) // first is unchanged as struct is always passed by refernce
{
  while (f)
  {
    cout << f->data << endl;
    f = f->next;
  }
}
void Merge(struct Node *p, struct Node *q, struct Node **t)
{
  struct Node *last;
  if (p->data < q->data)
  {
    *t = last = p;
    p = p->next;
    (*t)->next = NULL;
  }
  else
  {
    *t = last = q;
    q = q->next;
    (*t)->next = NULL;
  }
  while (p && q)
  {
    if (p->data < q->data)
    {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p)
    last->next = p;
  if (q)
    last->next = q;
}
int main()
{
  int A[] = {2, 8, 10, 15};
  create(A, 4, &first);
  int B[] = {4, 6, 12, 14};
  create(B, 4, &second);
  // Display(second);
  // Display(first);
  Merge(first, second, &third);
  Display(third);
}