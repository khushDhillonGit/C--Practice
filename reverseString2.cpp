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
//     string reverseWords(string s) {
//     int i = 0;
//     string k = "";
//     bool on = false;
//     string word = "";
//     while(i<s.length()){
//         if(s[i] != ' '){
//             on = true;
//             word += s[i];
//         }
//         if(on == true && (s[i] == ' ' || i == s.length()-1)){
//             k = word + " " + k;
//             word = "";
//             on = false;
//         }
//         i++;
//     }
//     return k.substr(0,k.length()-1);
// }
string trim(string a){
    int i = 0,j = a.length()-1;
    while(i < a.length()-1){
        if(a[i] == ' '){
            i++;
        }else{
            break;
        }
    }
    while( j>0){
        if(a[j] == ' '){
            j--;
        }
        else{
            break;
        }
    }
    return a.substr(i,j-i+1);
};
string reverseWords(string s) {
    s = trim(s);
    s = " " + s;
    int i = s.length()-1,j = i;
    string k = "";
    while(i >= 0){
        if(s[i] == ' '){
            k += s.substr(i+1,j-i) + " ";
            while(s[i] == ' ' && i >0){
                i--;
            }
            j = i;
            if(i==0){
                break;
            }
        }else{
            i--;
        }
         
    }
    return k.substr(0,k.length()-1);
}
int main()
{
    cout << reverseWords("a good   example") <<endl;
}