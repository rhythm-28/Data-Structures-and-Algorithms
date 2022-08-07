// Reverse a stack (using recursion)

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

void reverse(stack &s)
{
    // base case
    if(s.empty())
    return;

    // recursive case
    int y=s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s,y,0);
}

int main()
{
    stack s;
    int n;

    cin>>n;
    input(s,n);

    print(s,n);
    reverse(s);
    print(s,n);
    return 0;
}