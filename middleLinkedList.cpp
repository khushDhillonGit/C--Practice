// Boiler plate for c++ competative
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
   ListNode* middleNode(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        int l = 0;

        ListNode * p = head;
        while(p->next != NULL){
            l++;
            p = p->next;
        }
        l/=2;
        //l%2==0?l++:true;
        p = head;
        while(l != 0){
            p = p->next;
            l--;
        }
        return p;

    }
int main()
{
    
}