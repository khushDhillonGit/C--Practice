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
int check(char* s,int l)
{
    int i=0,j=l-1;
    while(i<j){
        if(s[i++] != s[j--]){return --i;}
    }
    return -1;
}

bool validPalindrome(string s)
{
    int i = check(&s[0],s.length());
    if(i == -1)return true;
    int j = s.length()-i-1;
    if(check(&s[i+1],j-i) == -1 || check(&s[i],j-i) == -1){
        return true;
    }
    return false;
}

int main()
{
    string a = "ebcbbececabbacecbbcbe";
    cout << validPalindrome(a) << endl;
}