// Matrix Chain Multiplication
// Find the minimum steps required to multiply all the given matrices

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int count_min_steps(int start,int end,int a[],int dp[][10])
{
    // 1 matrix
    if(start==end)
    return 0;

    // already done
    if(dp[start][end]!=-1)
    return dp[start][end];

    // else find minimum steps
    // pivot
    int ans=INT_MAX;
    for(int pivot=start;pivot<end;pivot++)
    {
        int left=count_min_steps(start,pivot,a,dp);
        int right=count_min_steps(pivot+1,end,a,dp);
        int current=a[start-1]*a[pivot]*a[end];
        int steps=left+right+current;
        
        ans=min(steps,ans);
    }
    dp[start][end]=ans;
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,i,j,a[10],dp[10][10];
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        dp[i][j]=-1;
    }
    
    // rows of all matrices and column of last
    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<count_min_steps(1,n-1,a,dp);

    return 0;
}