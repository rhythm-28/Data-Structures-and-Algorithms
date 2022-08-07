// To find maximum area under histogram

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

int histogram(int n,int a[])
{
    int max=0,i=0,h,area;
    stack s;
    s.push(i);
    for(i=1;i<n;i++)
    {
        while(!s.empty() && a[i]<a[s.top()])
        {
            h=a[s.top()];
            s.pop();

            if(!s.empty())
            area=h*(i-s.top()-1);

            else
            area=h*i;

            if(area>max)
            max=area;
        }
        s.push(i);
    }
    while(!s.empty())
    {
        h=a[s.top()];
        s.pop();

        if(!s.empty())
        area=h*(i-s.top()-1);

        else
        area=h*i;
        
        if(area>max)
        max=area;
    }
    return max;
}

int main()
{
    stack s;
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<histogram(n,a);
    return 0;
}