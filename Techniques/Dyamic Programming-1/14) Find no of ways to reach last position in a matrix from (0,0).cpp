// Find no of ways to reach last position in a matrix from (0,0) 
// can only move right and down ->1 step at a time
// O(n^2)

#include<iostream>
using namespace std;

#define MOD 1000000007

long long int min_ways(long long int dp[100][100],long long int n,long long int m)
{
    if(dp[0][0]==-1 || dp[n-1][m-1]==-1)
    return 0;

    long long int i,j;
    dp[0][0]=1;
    for(j=1;j<m;j++)
    {
        if(dp[0][j]==-1)
        break;
        
        dp[0][j]=1;
    }
    for(i=1;i<n;i++)
    {
        if(dp[i][0]==-1)
        break;

        dp[i][0]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {   
            if(dp[i][j]!=-1)
            {
                if(dp[i][j-1]!=-1)
                dp[i][j]=dp[i][j-1]%MOD;

                if(dp[i-1][j]!=-1)
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }            
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    long long i,j,n,m,p,x,y,dp[100][100];
    cin>>n>>m>>p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        dp[i][j]=0;
    }
    for(i=0;i<p;i++)
    {
        cin>>x>>y;
        dp[x-1][y-1]=-1;
    }
    cout<<min_ways(dp,n,m);
    return 0;
}