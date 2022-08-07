// Find how many binary search trees can be formed using n nodes with values 1,2,3,....,n

// Catalan number

#include<iostream>
using namespace std;

int catalan(int n)
{
    if(n==0)
    return 1;

    int sum=0;
    for(int i=1;i<=n;i++)
    sum+=(catalan(i-1)*catalan(n-i));

    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<catalan(n);
    return 0;
}