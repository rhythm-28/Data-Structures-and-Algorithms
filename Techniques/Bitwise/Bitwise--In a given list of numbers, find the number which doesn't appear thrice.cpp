// In a given list of numbers, find the number which doesn't appear thrice

#include<iostream>
using namespace std;

int find_unique(int n)
{
    int i,a,j,b[64]={0},p,ans;
    for(i=0;i<n;i++)
    {
        cin>>a;
        j=0;
        while(a>0)
        {
            b[j]+=(a&1);
            a=a>>1;
            j++;
        }
    }
    p=1;
    ans=0;
    for(i=0;i<64;i++)
    {
        b[i]%=3;
        ans+=(b[i]*p);
        p*=2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<find_unique(n);
    return 0;
}