// Insert a given element to bottom of stack

#include<iostream>
#include<vector>
using namespace std;

class stack
{
    vector<int> a;
    public:
    
    void push(int data)
    {
        a.push_back(data);
    }

    bool empty()
    {
        return a.size()==0;
    }   

    void pop()
    {
        if(empty()==0)
        a.pop_back();
    }

    int top()
    {
        int n=a.size();
        return a[n-1]; 
    }
};

void input(stack &s, int n)
{
    int d,i;
    for(i=0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
}

void print(stack s, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insert_at_bottom(stack &s,int &x,int y)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    y=s.top();
    s.pop();
    insert_at_bottom(s,x,y);
    s.push(y);
}

int main()
{
    stack s;
    int n,x;

    cin>>n;
    input(s,n);
    cin>>x;

    print(s,n);
    insert_at_bottom(s,x,0);
    n++;
    print(s,n);
    return 0;
}