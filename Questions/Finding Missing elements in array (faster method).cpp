// Finding Missing elements in array

#include<iostream>

using namespace std;
int main()
{
    int n,a[20],i,max,min,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    int *b;
    b=new int[max];
    for(i=0;i<max;i++)
    b[i]=0;
    for(i=0;i<n;i++)
    b[a[i]]++;
    for(i=min;i<=max;i++)
    {
        if(b[i]==0)
        cout<<i<<" ";
    }
    return 0;
}