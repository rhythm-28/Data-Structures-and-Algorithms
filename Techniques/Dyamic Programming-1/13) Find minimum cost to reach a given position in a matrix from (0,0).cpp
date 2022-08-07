// Find minimum cost to reach a given position in a matrix from (0,0)
// O(n)

#include<iostream>
#include<algorithm>
using namespace std;

int min_cost(int a[100][100],int dp[100][100],int destination_x,int destination_y)
{
    for(int i=0;i<destination_x;i++)
    {
        for(int j=0;j<destination_y;j++)
        {
            if(i==0 && j==0)
            dp[i][j]=a[i][j];

            else if(i==0)
            dp[i][j]=dp[i][j-1]+a[i][j];

            else if(j==0)
            dp[i][j]=dp[i-1][j]+a[i][j];

            else
            dp[i][j]=a[i][j]+min(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[destination_x-1][destination_y-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a[100][100],i,j,n,m,dp[100][100];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>a[i][j];
    }
    int destination_x,destination_y;
    cin>>destination_x>>destination_y;
    cout<<min_cost(a,dp,destination_x,destination_y);
    return 0;
}