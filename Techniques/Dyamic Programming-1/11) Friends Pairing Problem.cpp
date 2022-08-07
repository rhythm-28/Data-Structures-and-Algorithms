// Friends Pairing Problem
// Find no of ways in which a group of friends can go to a party if each guy can either go alone or in a pair

#include<iostream>
using namespace std;

int find_ways(int n,int dp[])
{
    if(n<=1)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    dp[n]=find_ways(n-1,dp) + (n-1)*find_ways(n-2,dp);
    return dp[n];
}

int main()
{
    int n,dp[10000];
    cin>>n;
    for(int i=0;i<=n;i++)
    dp[i]=-1;
    cout<<find_ways(n,dp);
    return 0;
}