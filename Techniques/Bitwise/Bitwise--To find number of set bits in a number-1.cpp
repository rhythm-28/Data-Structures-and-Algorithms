// To find number of set bits in a number
// O(logn)

#include<iostream>
#include<math.h>

using namespace std;

int getBit(int n,int i)
{
    int mask=(1<<i);
    int bit = (mask&n);
    if(bit==0)
    return 0;
    else
    return 1;
}

int main()
{
    int n,i,ans=0;
    cin>>n;
    for(i=0;i<=log2(n);i++)
    ans+=getBit(n,i);
    cout<<ans;
    return 0;
}