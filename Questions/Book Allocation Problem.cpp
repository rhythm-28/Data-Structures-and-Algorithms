// Book Allocation Problem

#include<iostream>
using namespace std;

bool check(int cur,int a[],int n,int m)
{
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(m==0)
        return false;
        
        if(b+a[i]<=cur)
        b+=a[i];

        else
        {
            m--;
            b=a[i];
        }
    }
    if(m==0)
    return false;
    else
    return true;
}

int book_allocation(int a[],int n,int m)
{   
    int min=a[n-1];
    int max=0;
    for(int i=0;i<n;i++)
    max+=a[i];

    // iterating over min to max using binary search
    int start=min,end=max,cur,ans;
    while(start<=end)
    {
        cur=(start+end)/2;
        if(check(cur,a,n,m))
        {
            ans=cur;
            end=cur-1;
        }

        else
        start=cur+1;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t,n,a[1000],i,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        cin>>a[i];
        cout<<book_allocation(a,n,m)<<endl;
    }

    return 0;
}