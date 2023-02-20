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
   bool isPalindrome(string s) {
    int i=0,j=s.length()-1;

    while(i < j){
        if(!isalnum(s[i])){
            i++;
        }
        else if(!isalnum(s[j]))
        {
            j--;
        }
        else 
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }else{
            i++;
            j--;
        }
        
    }
    return true;

}
int main()
{   
    cout << isPalindrome("A man, a plan, a canal: Panama") <<endl;
}