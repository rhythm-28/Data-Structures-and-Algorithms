// to create a queue class using 2 stacks

#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    stack<int> s1,s2;
    public:
    void push(int data)
    {
        if(s1.empty())
        s2.push(data);
        else
        s1.push(data);
    }
    void pop()
    {
        if(s1.empty())
        {
            while(s2.size()>1)
            {
                s1.push(s2.top());
                s2.pop();
            }
            s2.pop();
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            while(s1.size()>1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    int front()
    {
        int fronta;
        if(s1.empty())
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            fronta=s1.top();
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            fronta=s2.top();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return fronta;
    }
    bool empty()
    {
        if(s1.empty() && s2.empty())
        return  true;
        else
        return false;
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
        cout<<b.front()<<" ";
        b.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    Queue b;
    input(b,n);
    print(b);
    return 0;
}