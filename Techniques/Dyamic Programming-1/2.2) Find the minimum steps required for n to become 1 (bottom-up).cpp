// Find the minimum steps required for n to become 1
// n can become n/3 if n is divisible by 3
// n can become n/2 if n is divisible by 2
// n can become n-1

// Bottom-UP Approach
// Time: O(n)
// Space: O(n) 

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minimum_steps(int n)
{
    int dp[1000],x,y,z;
    dp[1]=0;

    for(int i=2;i<=n;i++)
    {
        x=INT_MAX,y=INT_MAX,z=INT_MAX;
        
        if(i%3==0)
        x=dp[i/3];

        if(i%2==0)
        y=dp[i/2];

        z=dp[i-1];

        dp[i]=min(min(x,y),z)+1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<minimum_steps(n);
    return 0;
}