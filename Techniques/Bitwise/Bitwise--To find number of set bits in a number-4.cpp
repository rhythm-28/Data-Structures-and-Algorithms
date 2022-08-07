// To find number of set bits in a number

#include<iostream>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    cout<<__builtin_popcount(n);
    return 0;
}