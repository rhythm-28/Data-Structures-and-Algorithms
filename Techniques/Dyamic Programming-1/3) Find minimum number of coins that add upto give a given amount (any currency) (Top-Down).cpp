// Find minimum number of coins that add upto give a given amount (any currency)
// Top-Down Approach
// Time: O(n*k)
// Space: O(n)

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int make_change(int a[],int k,int m,int dp[])
{
    int i,cur,ans=INT_MAX;

    if(m==0)
    return 0;
    
    if(dp[m]!=-1)
    return dp[m];

    for(i=0;i<k;i++)
    {
        if(m>=a[i])
        {
            cur=make_change(a,k,m-a[i],dp);
            ans=min(cur,ans);
        }
    }
    dp[m]=ans+1;
    return dp[m];
}

int main()
{
    //int a[]={1,2,5,10,20,50,100,200,500,2000};
    int a[]={1,7,10};
    int k=sizeof(a)/sizeof(int);
    int m;
    cin>>m;

    int dp[1000];
    for(int i=0;i<=m;i++)
    dp[i]=-1;

    cout<<make_change(a,k,m,dp);
    return 0;
}