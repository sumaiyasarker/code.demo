


#include <iostream>
#define MAXSIZE 100

 

using namespace std;

 

int queue[MAXSIZE];
int front = -1;
int rear = -1;

 

void enqueue(int element)
{
    if (rear == MAXSIZE - 1)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = element;
    }
}

 

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow" << endl;
    }
    else
    {
        front = front + 1;
    }
}

 

void peek()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << queue[front] << endl;
    }
}

 

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

 

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peek();
    dequeue();
    display();
    peek();
    return 0;
}

