// Find no of ways to reach a given position in a matrix from (0,0) if no cells are blocked
// O(n)

#include<iostream>
#include<algorithm>
using namespace std;

int factorial(int n)
{
    int i,x=1;
    for(i=1;i<=n;i++)
    x=x*i;
    return x;
}

int ways(int a[100][100],int dp[100][100],int destination_x,int destination_y)
{
    int numerator=factorial(destination_x-1+destination_y-1);
    int denominator=factorial(destination_x-1)*factorial(destination_y-1);
    return numerator/denominator;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a[100][100],i,j,n,m,dp[100][100];
    int destination_x,destination_y;
    cin>>destination_x>>destination_y;
    cout<<ways(a,dp,destination_x,destination_y);
    return 0;
}