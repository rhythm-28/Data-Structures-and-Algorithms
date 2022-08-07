// To update (i)th bit with 0/1 as asked by user

#include<iostream>
using namespace std;

int clearBit(int n,int i)
{
    int mask=~(1<<i);
    n=n&mask;
    return n;
}

int updateBit(int n,int i,int v)
{
    n=clearBit(n,i);
    int mask=(v<<i);
    n=n|mask;
    return n;
}

int main()
{
    int n,i,v;
    cin>>n>>i>>v;
    cout<<updateBit(n,i,v);
    return 0;
}