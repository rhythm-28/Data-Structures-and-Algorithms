// Given length of rod and price of rod wrt length, find maximum profit that can be made by selling rod
// Rod can be cut and sold in pieces
// Top-Bottom Approach
// Time: O()
// Space: O()

#include<iostream>
#include<algorithm>
using namespace std;

int rod_cut(int a[],int length,int dp[])
{
    // base case
    if(length==0)
    return 0;

    if(dp[length]!=-1)
    return dp[length];

    // recursive case
    int cur,ans=0,cut;
    for(int i=0;i<length;i++)
    {
        cut=i+1;
        cur=a[i]+rod_cut(a,length-cut,dp);

        ans=max(ans,cur);
    }
    dp[length]=ans;
    return ans;
}

int main()
{
    int n,i,a[1000],dp[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<=n;i++)
    dp[i]=-1;

    cout<<rod_cut(a,n,dp);
    return 0;
}