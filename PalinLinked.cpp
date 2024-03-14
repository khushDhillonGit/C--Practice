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
ListNode * createLinked(int *a,int l){
    ListNode *h = NULL;
    ListNode *p = h;

    for(int i=0;i<l;i++){
        ListNode * temp = (ListNode*) malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->val = a[i];
        if(i==0){
            h = temp;
            p = temp;
        }else{
            p->next = temp;
            p = p->next;
        }
    }
    return h;
}

void insert(ListNode **h,int pos,int val){
    ListNode *t = (ListNode*)malloc(sizeof(ListNode));
    t->val = val;
    t->next = NULL;

    if(pos == 0){
        t->next = *h;
        *h = t;
    }
    else{
        ListNode *k=*h;
        while(pos>1){
            k = k->next;
            pos--;
        }
        t->next = k->next;
        k->next = t;
    }
}
void deleteE(ListNode **h,int pos){
    ListNode *t = *h;
    if(pos == 1){
        *h = (*h)->next;
        delete t;
    }else{
        while(pos>2 && t){
            t = t->next;
            pos--;
        }
        ListNode *k = t->next;
        t->next = k->next;
        delete k;
    }

}
void printLinked(ListNode *h){
    while(h != NULL){
        cout << h->val << endl;
        h = h->next;
    }
}
    bool isPalin(vector<int> *k,int l){
        int i=0,j=l-1;
        while(i<=j){
            cout << (*k)[i] << endl;
            cout << (*k)[j] << endl;
            if(k[i] != k[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *q = head;
        vector<int> k;
        while(q != NULL){
            k.push_back(q->val);
            q = q->next;
        }
        return isPalin(&k,k.size());

    }
int length(ListNode **h){
    ListNode *t = *h;
    int l =0;
    while (t)
    {
        t=t->next;
        l++;
    }
    return l;
    
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListNode *h = createLinked(a,sizeof(a)/sizeof(int));
    // cout << isPalindrome(h) << endl;
    // insert(&h,0,3);
    deleteE(&h,1);
    printLinked(h);
}