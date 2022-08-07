// To set (i)th bit of a number 
// i.e. to set (i)th bit as 1

#include<iostream>
using namespace std;

int setBit(int n,int i)
{
    int mask=(1<<i);
    n=(mask|n);
    return n;
}

int main()
{
    int n,i;
    cin>>n>>i;
    cout<<setBit(n,i);
    return 0;
}