// Identify prime numbers among list of numbers
// [O(n*log (log n))]

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    a.push_back(0);
    a[0]=a[1]=0;
    a[2]=1;
    for(i=3;i<=n;i=i+2)
    a[i]=1;
    for(i=3;i<=n;i++)
    {
        if(a[i]==1)
        {
            for(j=i*i;j<=n;j=j+i)
            a[j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        cout<<i<<" ";
    }
    return 0;
}