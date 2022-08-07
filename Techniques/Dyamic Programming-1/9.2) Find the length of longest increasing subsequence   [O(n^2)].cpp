// Find the length of longest increasing subsequence
// O(n^2)

#include<iostream>
#include<climits>
using namespace std;

int longest(int n,int a[])
{
    int i,j,x,dp[10000];	

    // dp[i] => last element of increaseing subsequence with length i

    dp[0]=INT_MIN;
    for(i=1;i<=n;i++)
    dp[i]=INT_MAX;

    for(i=0;i<n;i++)
    {
        x=a[i];
        for(j=0;j<n;j++)
        {
            if(dp[j]<x && x<dp[j+1])
            {
                dp[j+1]=x;
                break;
            }
        }
    }

    for(i=n;i>0;i--)
    {
        if(dp[i]!=INT_MAX)
        return i;
    }
}

int main()
{
    int i,n,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<longest(n,a);
    return 0;
}