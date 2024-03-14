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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Trie
{
    private:
        Trie *node[26];
        bool isEnd;
    public:
        
        Trie()
        {
            isEnd = false;
            for(int i=0;i<26;i++)
            {
                node[i] = nullptr;
            }
        }

        void insert(string word)
        {
            Trie* temp = node;
            for(char a: word)
            {
                if(temp->node[a - 'a'] == nullptr)
                {
                    temp->node[a - 'a'] = new Trie();
                }
                temp = temp->node[a - 'a'];
            }
            temp->isEnd = true;
        }

        bool contains(string word)
        {
            Trie* temp = node;
            for(char a: word)
            {
                if(temp->node[a - 'a'] == nullptr) return false;
                temp = temp->node[a - 'a'];
            }
            if(temp->isEnd) return true;
            return false;
        }

        bool startsWith(string word)
        {
            Trie* temp = node;
            for(char a: word)
            {
                if(temp->node[a - 'a'] == nullptr) return false;
                temp = temp->node[a - 'a'];
            }
            return true;
        }
}

int main()
{
    Trie trie = new Trie();
    trie.insert();
    
}