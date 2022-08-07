// Prime Factorization
// For 1 test case = [O(n*log (log n))]
// For n test cases = O(n*logn)

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b;
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
        b.push_back(i);
    }

    for(i=0;b[i]<=sqrt(n);i++)
    {
        while((n%b[i])==0)
        {
            n=n/b[i];
            cout<<b[i]<<" ";
        }
    }
    if(n!=1)
    cout<<n;
    return 0;
}