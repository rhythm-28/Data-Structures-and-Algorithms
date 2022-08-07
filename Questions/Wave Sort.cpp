// Wave Sort
// sort an unsorted array in the form of a wave
/*

*       *       *       *
    *       *       *

*/

#include<iostream>
#include<algorithm>
using namespace std;

void wave_sort(int n,int a[])
{
    for(int i=0;i<n;i=i+2)
    {
        if(i==0)
        {
            if(a[i]<a[i+1])
            swap(a[i],a[i+1]);
        }
        else if(i==n-1)
        {
            if(a[i]<a[i-1])
            swap(a[i],a[i-1]);
        }
        else
        {
            if(a[i]<a[i-1])
            swap(a[i],a[i-1]);

            if(a[i]<a[i+1])
            swap(a[i],a[i+1]);
        }
    }
}

int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    wave_sort(n,a);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}