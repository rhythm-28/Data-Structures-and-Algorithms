// Optimal Game Strategy    

#include<iostream>
#include<algorithm>
using namespace std;

int game(int a[],int i,int j,int dp[10][10])
{
    if(i>j)
    return 0;   

    if(dp[i][j]!=-1)
    return dp[i][j];

    int option1=a[i]+min(game(a,i+2,j,dp),game(a,i+1,j-1,dp));
    int option2=a[j]+min(game(a,i,j-2,dp),game(a,i+1,j-1,dp));
    
    dp[i][j]=max(option1,option2);
    return dp[i][j];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,i,j,a[1000],dp[10][10];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        dp[i][j]=-1;
    }
    cout<<game(a,0,n-1,dp);
    cout<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}