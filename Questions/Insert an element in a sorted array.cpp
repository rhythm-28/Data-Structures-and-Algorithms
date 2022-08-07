// Insert an element in a sorted array

#include<iostream>
using namespace std;

int main()
{
    int i,x,n,a[10];
    cin>>n>>x;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-1;a[i]>x;i--)
        a[i+1]=a[i];
    a[i+1]=x;
    for(i=0;i<=n;i++)
        cout<<a[i];
    return 0;
}