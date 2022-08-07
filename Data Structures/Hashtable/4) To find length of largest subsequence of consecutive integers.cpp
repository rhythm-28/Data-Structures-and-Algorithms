// To find length of largest subsequence of consecutive integers

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int function(int a[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(m.find(x)==m.end())
        {
            auto i=m.find(x-1);
            auto j=m.find(x+1);

            // both not found
            if(i==m.end() && j==m.end())
            m[x]=1;

            // found x-1 but not found x+1
            else if(i!=m.end() && j==m.end())
            {
                int l=m[x-1];
                m[x]=l+1;
                m[x-l]=l+1;
            }

            // not found x-1 but found x+1
            else if(i==m.end() && j!=m.end())
            {
                int l=m[x+1];
                m[x]=l+1;
                m[x+l]=l+1;
            }
            // found both x-1 and x+1
            else if(i!=m.end() && j!=m.end())
            {
                int l1=m[x-1];
                int l2=m[x+1];
                m[x]=l1+1+l2;
                m[x-l1]=l1+1+l2;
                m[x+l2]=l1+1+l2;
            }
        }
    }
    int max_streak=1;
    for(auto p:m)
    max_streak=max(max_streak,p.second);
    
    return max_streak;
}

int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<function(a,n);
    return 0;
}
