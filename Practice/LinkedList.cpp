#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;

  ListNode()
  {
    val = -1;
    next = NULL;
  }

  ListNode(int val): val(val)
  {
    next = NULL;
  }
  ListNode(int val, ListNode* next): val(val), next(next)
  {

  }
};

ListNode *head;

void InsertAtBeginning(int x)
{
    ListNode *node = new ListNode(x,head);
    head = node;
}

void InsertAtEnd(int x)
{
    
    ListNode *node = new ListNode(x,NULL);
    node->next = head;

    if(node->next == NULL)
    {
      head = node;
      return;
    }

    while(node->next->next != NULL)
    {
        node->next = node->next->next;      
    }

    node->next->next = node;
    node->next = NULL;
}

void InsertAtPlace(int x, int place)
{

  if(place < 1) return;

  ListNode *node = new ListNode(x);
  ListNode *temp = node;
  temp->next = head;

  if(head == NULL || place == 1)
  {
    head = node;
    return;
  }

  while(place > 1 && temp->next != NULL)
  {
    temp = temp->next;
    place--;
  }
    node->next = temp->next;
    temp->next = node;
    delete temp;
    delete node;
}

void PrintListNode()
{
    ListNode *temp = head;
    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

// void DeleteTheNthNode(int place)
// {
//   if(place < 1) return;
//   if(head == NULL) return;

//   ListNode *prev = head;
//   if(place == 1)
//   {
//     head = prev->next;
//     delete prev;
//     return;
//   }
//   while(place > 2 && curr->next != NULL)
//   {
//     curr = curr->next;
//   }

//   ListNode *curr = prev->next;
//   prev->next = curr->next;
//   delete curr;
// }

void ReverseLinkedList()
{
  if(head == NULL) return;
  ListNode *prev = head, *curr = prev->next;
  while(curr != NULL)
  {
    prev->next = curr->next;
    curr->next = head;
    head = curr;
    curr = prev->next;
  }
}

void PrintRecursion(ListNode *head)
{
  if(head == NULL)
  {
    return;
  }

  cout << head->val << endl;
  PrintRecursion(head->next);
}

void ReverseLinkedListRecursion(ListNode *prev,ListNode *curr)
{
  if(curr == NULL)
  {
    head = prev;
    return;
  }
  ReverseLinkedListRecursion(curr, curr->next);
  curr->next = prev;
}

int main()
{
  int a[5] = {1,2,3,4,5};
  for (auto i : a)
  {
    // InsertAtBeginning(i);
    InsertAtEnd(i);
  }
  
  ReverseLinkedListRecursion(NULL,head);
  PrintRecursion(head);
}