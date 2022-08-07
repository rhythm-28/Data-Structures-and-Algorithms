// Find minimum number of coins that add upto give a given amount (any currency)
// Bottom-Up Approach
// Time: O(n*k)
// Space: O(n)

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int make_change(int m,int a[],int k)
{
    if(m==0)
    return 0;
    
    int dp[1000],i,j,ans,cur;
    dp[0]=0;
    for(i=1;i<=m;i++)
    {
        ans=INT_MAX;
        for(j=0;j<k;j++)
        {
            if(m>=a[j])
            cur=dp[i-a[j]];

            ans=min(ans,cur);
        }
        dp[i]=ans+1;
    }
    return dp[m];
}

int main()
{
    //int a[]={1,2,5,10,20,50,100,200,500,2000};
    int a[]={1,7,10};
    int k=sizeof(a)/sizeof(int);
    int m;
    cin>>m;

    cout<<make_change(m,a,k);
    return 0;
}