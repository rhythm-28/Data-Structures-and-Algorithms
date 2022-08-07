// Travelling Salesman Problem
// DP based

#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int tsp(int mask,int cur_city,int final,int v,int a[][100],int dp[][100])
{
    // base case
    if(mask==final)
    return a[cur_city][0];

    // already occured
    if(dp[mask][cur_city]!=-1)
    return dp[mask][cur_city];
    
    int s,cur_ans,ans=INT_MAX;
    for(int i=0;i<v;i++)
    {
        s=pow(2,i);
        // city not visited
        if( (mask & s) ==0 )
        {
            cur_ans=a[cur_city][i]+ tsp(mask|(1<<i),i,final,v,a,dp);
            ans=min(ans,cur_ans);
        }
    }
    return dp[mask][cur_city]=ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,x,i,j,e,weight,a[100][100],dp[100][100];
    cin>>v>>e;
    for(x=0;x<e;x++)
    {
        cin>>i>>j>>weight;
        a[i][j]=weight;
    }
    for(i=0;i<pow(2,v);i++)
    {
        for(j=0;j<v;j++)
        dp[i][j]=-1;
    }
    int final=pow(2,v)-1;
    cout<<tsp(1,0,final,v,a,dp);
    return 0;
}