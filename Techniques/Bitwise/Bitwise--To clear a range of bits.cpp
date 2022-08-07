// To clear a range of bits

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

int main()
{
    int n,i,j;
    cin>>n>>i>>j;
    cout<<clear_range_of_Bits(n,i,j);
    return 0;
}