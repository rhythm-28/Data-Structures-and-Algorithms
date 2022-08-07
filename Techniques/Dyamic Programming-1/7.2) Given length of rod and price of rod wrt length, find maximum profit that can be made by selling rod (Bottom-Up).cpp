// Given length of rod and price of rod wrt length, find maximum profit that can be made by selling rod
// Rod can be cut and sold in pieces
// Bottom-Up Approach
// Time: O(n^2)
// Space: O(n)

#include <iostream>
#include<algorithm>
using namespace std;

int rod_cut(int a[],int n)
{
	int cur,i,j,dp[1000],ans,cut;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		ans=0;
		for(j=0;j<i;j++)
		{
			cut=j+1;
			cur=a[j]+dp[i-cut];

			ans=max(ans,cur);
		}
		dp[i]=ans;
	}
	return dp[n];
}

int main() 
{
	int n,i,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<rod_cut(a,n);
	return 0;
}
