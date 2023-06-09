#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int F, R, maxsize;
    int *queue;
    // Queue (int ms=100) : maxsize(ms),f(0),r(ms-1),
    Queue(int c)
    {
        F = R = 0;
        maxsize = c;
        queue = new int;
    }
    void enQueue(int data)
    {
        if (size == maxsize)
        {
            cout << "IsFull" << endl;
            return;
        }
        else
        {
            R = (R + 1) % maxsize;
        }
        queue[R] = data;
    }
    void deQueue()
    {
        if (isEmpty() == true)
        {
            cout << "Queue Empty";
        }
        else if (F == R)
        {
            F = -1;
            R = -1;
        }
        else
        {

            F = (F + 1) % maxsize;
        }
    }
    bool isEmpty()
    {
        if (F == -1 && R == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Display()
    {
        if (isEmpty() == true)
        {
            cout << "EMty" << endl;
        }
        else
        {
            for (int i = F; i <= R; i++)
            {
                cout << queue[i] << " ";
            }
        }
    }
}

void main(){
    return 0;
}