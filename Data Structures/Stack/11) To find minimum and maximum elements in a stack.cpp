// To find minimum and maximum elements in a stack

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class stack
{
    // restricting access to vector
    vector<int> a;
    vector<int> mins;
    vector<int> maxs;
    public:
    
    // to insert data at the top
    void push(int data)
    {
        a.push_back(data);
        int cur_min=data;
        int cur_max=data;
        if(!mins.empty() && !maxs.empty())
        {
            cur_min=min(cur_min,mins[mins.size()-1]);
            cur_max=max(cur_max,maxs[maxs.size()-1]);
        }
        mins.push_back(cur_min);
        maxs.push_back(cur_max);
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
        {
            a.pop_back();
            mins.pop_back();
            maxs.pop_back();
        }
    }

    // to return the topmost element of stack
    int top()
    {
        int n=a.size();
        return a[n-1]; 
    }

    int getMin()
    {
        return mins[mins.size()-1];
    }

    int getMax()
    {
        return maxs[maxs.size()-1];
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

int main()
{
    stack s;
    int n;
    cin>>n;
    input(s,n);
    print(s,n);
    cout<<s.getMin()<<endl<<s.getMax();
    return 0;
}