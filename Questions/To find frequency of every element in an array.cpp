// to find frequency of every element in an array
// Hashing
// [O(m)/ O(n)]
#include<iostream>
using namespace std;
int main()
{
    int n,a[100],b[1000],i,c,m;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    m=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>m)
        m=a[i];
    }
    for(i=0;i<=m;i++)
    b[i]=0;
    for(i=0;i<n;i++)
    {
        c=a[i];
        b[c]++;
    }
    for(i=0;i<=m;i++)
    {
        if(b[i]!=0)
        cout<<i<<"-"<<b[i]<<endl;
    }
    return 0;
}