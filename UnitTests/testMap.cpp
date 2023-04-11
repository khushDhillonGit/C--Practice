// Boiler plate for c++ competative
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
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

int main()
{
    unordered_map<int,int> k;
    if(k[1]++ == 0){
        cout << "ok" << endl;
    }
    cout<<k[1]<<endl;

}