// Wine Selling 
/* 
Prices of wines in the first year are given
Price in y(th) year = Price in first year * y
Only first index and last index wine bottles can be sold 
Only 1 wine bottle can be sold every year

Find the maximum profit that can be made by selling all the bottles
*/
#include<iostream>
#include<algorithm>
using namespace std;

int maximum_profit(int a[],int i,int j,int y,int dp[][1000])
{
    if(i>j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int option1=a[i]*y+maximum_profit(a,i+1,j,y+1,dp);
    int option2=a[j]*y+maximum_profit(a,i,j-1,y+1,dp);

    dp[i][j]=max(option1,option2);

    return dp[i][j];
}

int main()
{
    int n,i,j,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    int dp[1000][1000];
    for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
        dp[i][j]=-1;
    }

    cout<<maximum_profit(a,0,n-1,1,dp);
    return 0;
}