#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  char *key;
  char *val;
};
struct HashMap
{
  Node **array;
  int size;
  int count;
};
Node *createNode(char *key, char *val)
{
  Node *a = (Node *)malloc(sizeof(struct Node));
  a->key = new char;
  a->val = new char;

  strcpy(a->key, key);
  strcpy(a->val, val);

  return a;
}

HashMap *createMap(int size)
{
  HashMap *a = (HashMap *)malloc(sizeof(HashMap));
  a->array = (Node **)calloc(size, sizeof(Node *));
  a->count = 0;
  a->size = size;
  for (int i = 0; i < size; i++)
  {
    a->array[i] = NULL;
  }
  return a;
}
void freeNode(Node *a)
{
  free(a->key);
  free(a->val);
  free(a);
}

void freeMap(HashMap *a)
{
  for (int i = 0; i < a->size; i++)
  {
    freeNode(a->array[i]);
  }
  free(a->array);
  free(a);
}
unsigned long hash(char *key)
{
  int k = 0;
}
int main()
{
}