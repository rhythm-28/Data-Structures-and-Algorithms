// Find the longest increasing subsequence 
// (Using Bottom-UP DP)
// O(n^2)

#include<iostream>
#include<algorithm>
using namespace std;

int longest(int a[],int n)
{
    int i,j,ans,dp[1000];

    // dp[i] => longest increasing subsequence upto i including a[i]

    for(i=0;i<n;i++)
    {
        ans=0;
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
            ans=max(ans,dp[j]);
        }
        dp[i]=ans+1;
    }
    ans=0;
    for(i=0;i<n;i++)
    ans=max(ans,dp[i]);
    return ans;
}
int main()
{  
    int n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<longest(a,n);
    return 0;
}