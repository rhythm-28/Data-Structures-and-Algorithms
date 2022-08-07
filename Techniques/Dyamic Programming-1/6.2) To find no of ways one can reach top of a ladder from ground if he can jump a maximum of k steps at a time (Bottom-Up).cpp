// To find no of ways one can reach top of a ladder from ground if he can jump a maximum of k steps at a time
// no of steps on ladder = n
// Bottom-Up 
// Time: O(n*k)
// Space: O(n)

#include<iostream>
using namespace std;

int find_ways(int n,int k)
{
    if(n==0)
    return 1;
    
    int dp[10000],i,j;
    dp[0]=1;    

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i-j>=0)
            dp[i]+=dp[i-j];
        }
    }

    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;

    cout<<find_ways(n,k);
    return 0;
}