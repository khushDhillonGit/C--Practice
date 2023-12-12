#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
};

int array[500];
int front = -1;
int rear = -1;

void push(int x)
{
    if(isFull) return;
    if(isEmpty()) front++;
    if(rear == 499) rear = -1;
    array[++rear] = x;
}

int pop()
{
    int index = front++;
    if(front > rear) front = rear == -1;
    return array[index];
}

bool isFull()
{
    return  (rear == (front - 1)) || (front == 0 && rear == 499);
}

int front()
{
    return array[front];
}

bool isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

int main()
{

}