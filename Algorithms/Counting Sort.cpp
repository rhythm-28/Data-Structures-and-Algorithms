// Counting Sort
// O(max_value-min_value)
#include<iostream>
using namespace std;
int main()
{
    int n,a[100],b[1000],d[1000],i,c,m;
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
    int k=0,j;;
    for(i=0;i<=m;i++)
    {
        if(b[i]!=0)
        {
            for(j=0;j<b[i];j++)
            {
                d[k]=i;
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    cout<<d[i]<<" ";
    return 0;
}