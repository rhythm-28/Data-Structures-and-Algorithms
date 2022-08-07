/*
find no of such pairs which fullfill the following:
1) i<j
2) a[i]>a[j]
*/

#include<iostream>
using namespace std;

int count(int a[],int n)
{
    int i,j,ctr=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            ctr++;
        }
    }
    return ctr;
}

int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<count(a,n);
    return 0;
}