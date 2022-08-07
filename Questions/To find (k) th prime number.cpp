// To find (k)th prime number
// [O(n*log (log n))]

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int n,i,j;
    n=10000;
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

    vector<int> b;
    int k;
    cin>>k;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
		b.push_back(i);
    }
	cout<<b[k-1];
    return 0;
}