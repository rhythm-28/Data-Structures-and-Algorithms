// Implement a stack class using 2 queues

#include<iostream>
#include<queue>
using namespace std;

class Stack
{
    queue<int> q1,q2;
    public:
    void push(int data)
    {
        if(q1.empty())
        {
            q1.push(data);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(data);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    void pop()
    {
        if(q1.empty())
        q2.pop();
        else
        q1.pop();
    }
    int top()
    {
        if(q1.empty())
        return q2.front();
        else
        return q1.front();
    }
    bool empty()
    {
        if(q1.empty() && q2.empty())
        return true;
        else
        return false;
    }
};

void input(Stack &s, int n)
{
    int d,i;
    for(i=0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
}

void print(Stack s, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    Stack s;
    int n;
    cin>>n;
    input(s,n);
    print(s,n);
    return 0;
}