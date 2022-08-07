// Replace some bits of a number by another number's bits

#include<iostream>
using namespace std;

int clear_range_of_Bits(int n,int i,int j)
{
    int x=~0;
    int a=( x << (j+1) );
    int b= ~ (x<<i);
    int mask=a|b;
    n=n&mask;
    return n;
}

int change(int n,int i,int j,int m)
{
    n=clear_range_of_Bits(n,i,j);
    int mask=(m<<i);
    int ans=n|mask;
    return ans;
}

int main()
{
    int n,i,j,m;
    cin>>n>>i>>j>>m;
    cout<<change(n,i,j,m);
    return 0;
}