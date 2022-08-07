// Find no of binary strings that can be formed without having consecutive 1s
// binary string => a strig having only 0s & 1s

#include<iostream>
using namespace std;

int find_ways(int n)
{
    if(n==0)
    return 1;
    else if(n==1)
    return 2;
    else
    return find_ways(n-1)+find_ways(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<find_ways(n);
    return 0;
}