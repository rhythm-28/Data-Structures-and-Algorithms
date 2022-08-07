// To find no of ways one can reach top of a ladder from ground if he can jump a maximum of k steps at a time
// no of steps on ladder = n
// Top to Bottom 
// Time: O(n*k)
// Space: O(n)

#include<iostream>
using namespace std;

int find_ways(int n,int k,int dp[])
{
    if(n==0)
    return 1;
    
    if(dp[n]!=-1)
    return dp[n];

    int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        ans+=find_ways(n-i,k,dp);
    }

    dp[n]=ans;

    return dp[n];
}

int main()
{
    int n,k,dp[1000];
    cin>>n>>k;
    for(int i=0;i<1000;i++)
    dp[i]=-1;
    cout<<find_ways(n,k,dp);
    return 0;
}