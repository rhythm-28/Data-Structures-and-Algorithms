// Array Rotation

#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,x,y;
    int a[50];
    cin>>n;
    for(k=0;k<n;k++)
    cin>>a[k];
    cin>>y;
    for(i=0;i<=y;i++)
    {
        x=a[0];
        for(j=0;j<n-1;j++)
        a[j]=a[j+1];
        a[n-1]=x;
    }
    for(k=0;k<n;k++)
    cout<<a[k];
    return 0;
}