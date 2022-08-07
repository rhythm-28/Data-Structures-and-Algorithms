// To form a stack of integers

#include<iostream>
#include<vector>
using namespace std;

class stack
{
    // restricting access to vector
    vector<int> a;
    public:
    
    // to insert data at the top
    void push(int data)
    {
        a.push_back(data);
    }

    // to check if stack is empty or not
    bool empty()
    {
        return a.size()==0;
    }   

    // to remove the topmost element in stack
    void pop()
    {
        // if stack is not empty, only then removal is possible
        if(empty()==0)
        a.pop_back();
    }

    // to return the topmost element of stack
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
}

int main()
{
    stack s;
    int n;
    cin>>n;
    input(s,n);
    print(s,n);
    return 0;
}