// To count no of divisors of a number
// O[n*log(logn)]

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

    // count denotes how many times a prime factor appears in factorization
    // divisors= (no of times a prime factor appears +1 ) * (no of times another prime factor appears +1) * ..... 

    int count=0,divisors=1;
    for(i=0;b[i]<=sqrt(n);i++)
    {
        count=0;
        while((n%b[i])==0)
        {
            n=n/b[i];
            count++;
        }
        divisors*=(count+1);
    }
    if(n!=1)
    divisors*=2;
    cout<<divisors;
    return 0;
}