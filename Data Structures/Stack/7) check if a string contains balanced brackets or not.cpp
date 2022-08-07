// check if a string contains balanced brackets or not

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class stack
{
    vector<T> a;
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

bool check(string a)
{
    stack<char> s;
    char c;
    int i,n=a.length();
    for(i=0;i<n;i++)
    {
        c=a[i];
        if(c=='(')
        s.push(c);
        else if(c==')')
        {
            if(s.empty())
            return false;
            else
            s.pop();
        }
    }
    if(s.empty())
    return true;
    else 
    return false;
}

int main()
{
    string a;
    getline(cin,a);
    bool ans=check(a);
    if(ans)
    cout<<"balanced";
    else
    cout<<"unbalanced";
    return 0;
}