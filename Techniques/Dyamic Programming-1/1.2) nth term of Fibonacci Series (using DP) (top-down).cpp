// nth term of Fibonacci Series (using DP)
// Top-Down Approach
// Time: O(n)
// Space : O(n)

#include<iostream>
using namespace std;

int fib(int n,int dp[])
{
    if(n==0 || n==1)
    return n;
    
    if(dp[n]!=0)
    return dp[n];

    dp[n]=fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main()
{
    int n,dp[1000]={0};
    cin>>n;
    cout<<fib(n,dp);
    return 0;
}