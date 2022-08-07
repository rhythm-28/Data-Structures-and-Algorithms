// To find (i)th bit of a number 

#include<iostream>
using namespace std;

int getBit(int n,int i)
{
    int mask=(1<<i);
    int bit= (mask&n);
    if(bit==0)
    return 0;
    else
    return 1;
}

int main()
{
    int n,i;
    cin>>n>>i;
    cout<<getBit(n,i);
    return 0;
}