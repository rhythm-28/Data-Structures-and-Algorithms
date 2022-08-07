// To form a stack of templates (int,char,vector,etc...)

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class stack
{
    // restricting access to vector
    vector<T> a;
    public:
    
    // to insert data at the top
    void push(T data)
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
    T top()
    {
        int n=a.size();
        return a[n-1]; 
    }
};

void input(stack<int> &s, int n)
{
    int d,i;
    for(i=0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
}

void print(stack<int> s, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    int n;
    cin>>n;
    input(s,n);
    print(s,n);
    return 0;
}