// To find no of ways one can reach top of a ladder from ground if he can jump a maximum of k steps at a time
// no of steps on ladder = n
// Bottom-Up 
// Time: O(n)
// Space: O(n)

#include<iostream>
using namespace std;

int find_ways(int n,int k)
{
    if(n==0)
    return 1;
    
    int dp[10000],i,j;
    dp[0]=dp[1]=1;

    for(i=2;i<=k;i++)
    dp[i]=2*dp[i-1];

    for(i=k+1;i<=n;i++)
    dp[i]=2*dp[i-1]-dp[i-k-1];

    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;

    cout<<find_ways(n,k);
    return 0;
}