// Reverse a stack (using another stack)
// Time O(n^2)
// Space O(n) 

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

// transfer m elements from b to a
void transfer(stack &a,stack &b,int m)
{
    for(int i=1;i<=m;i++)
    {
        a.push(b.top());
        b.pop();
    }
}

void reverse(stack &s,int n)
{
    stack t;
    int i,j,x;
    for(j=1;j<=n-1;j++)
    {
        // store the topmost element
        x=s.top();
        s.pop();

        // transfer other elements into temporary stack (those which have not been reversed)
        transfer(t,s,n-j);

        // place that topmost element into its correct posiition (position that should be after reverse)
        s.push(x);

        // transfer remaining elements back into original stack
        transfer(s,t,n-j);
    }
}

int main()
{
    stack s;
    int n;
    cin>>n;
    input(s,n);
    print(s,n);
    reverse(s,n);
    print(s,n);
    return 0;
}