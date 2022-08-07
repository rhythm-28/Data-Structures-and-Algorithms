// Find the minimum steps required for n to become 1
// n can become n/3 if n is divisible by 3
// n can become n/2 if n is divisible by 2
// n can become n-1

// Top-Down Approach
// Time: O(n)
// Space: O(n) 

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minimum_steps(int n,int dp[])
{
    if(n==1)
    return 0;   

    int x=INT_MAX,y=INT_MAX,z=INT_MAX,ans;

    if(n%3==0)
    {
        if(dp[n/3]==-1)
        x=minimum_steps(n/3,dp);

        else
        x=dp[n/3];
    }
    if(n%2==0)
    {
        if(dp[n/2]==-1)
        y=minimum_steps(n/2,dp);

        else
        y=dp[n/2];
    }
    
    if(dp[n-1]==-1)
    z=minimum_steps(n-1,dp);

    else
    z=dp[n-1];

    dp[n]=min(min(x,y),z)+1;
    return dp[n];
}

int main()
{
    int dp[1000],n;
    cin>>n;
    for(int i=0;i<n;i++)
    dp[i]=-1;
    cout<<minimum_steps(n,dp);
    return 0;
}