// Reverse a stack (using any DS)
// I am using a vector

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

void reverse(stack &s)
{
    vector<int> v;
    int y;
    while(s.empty()!=1)
    {
        y=s.top();
        v.push_back(y);
        s.pop();
    }
    int n=v.size();
    int i=0;
    while(i!=n)
    {
        y=v[i];
        s.push(y);
        i++;
    }
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