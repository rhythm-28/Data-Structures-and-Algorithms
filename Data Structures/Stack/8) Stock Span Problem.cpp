// Stock Span Problem

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

void stock_span(int prices[],int n,int span[])
{
    stack s;
    int i=0;

    // first element
    s.push(i);
    span[i]=1;

    for(i=1;i<n;i++)
    {
        while(!s.empty() && prices[s.top()] < prices[i])
        s.pop();

        if(s.empty())
        {
            span[i]=i+1;
            s.push(i);
        }
        
        else
        {
            span[i]=i-s.top();
            s.push(i);
        }
    }
}

int main()
{
    int i,n,prices[1000],span[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>prices[i];
    stock_span(prices,n,span);
    for(i=0;i<n;i++)
    cout<<span[i]<<" ";
    return 0;
}