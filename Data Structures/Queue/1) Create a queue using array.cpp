// Create a queue using array
// Queue => first in first out

#include<iostream>
using namespace std;

class Queue
{
    int csize;
    int *a;
    int f,r,n;

    public:

    // default constructor
    Queue()
    {

    }

    // parameterized constructor 
    Queue(int b)
    {
        n=b;
        a=new int[n];
        csize=0;
        f=0;
        r=n-1;
    }

    // check if queue is full
    bool full()
    {
        return csize==n;
    }

    // insert element at rear
    void push(int data)
    {
        if(!full())
        {
            r=(r+1)%n;
            a[r]=data;
            csize++;
        }
    }

    // check if queue is empty
    bool empty()
    {
        return csize==0;
    }

    // delete elements at end
    void pop()
    {
        if(!empty())
        {
            f=(f+1)%n;
            csize--;
        }
    }

    // check the front element
    int front()
    {
        if(!empty())
        return a[f];
    }

    ~Queue()
    {
        delete []a;
    }
};

void input(Queue &b,int n)
{
    int i,data;
    for(i=0;i<n;i++)
    {
        cin>>data;
        b.push(data);
    }
}

void print(Queue b)
{
    while(!b.empty())
    {
        cout<<b.front();
        b.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    Queue b(n);
    input(b,n);
    print(b);
    return 0;
}