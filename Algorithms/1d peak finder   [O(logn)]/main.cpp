// 1-D Peak Finder (only one)
/*
abcdefg
if b>=a & b>=c   => b is a peak
if a>=b  => a is a peak
if g>=f => g is a peak
*/

#include <iostream>

using namespace std;

int Peak(int a[],int l,int h,int n)
{
    int m;
    m=(l+h)/2;
    if((a[m-1]<=a[m] && a[m] >= a[m+1])  || (m==0 && a[m]>=a[m+1]) || (m==n-1 && a[m]>=a[m-1]))
        return m;
    else if(a[m-1] > a[m])
        return Peak(a,l,m-1,n);
    else if(a[m] < a[m+1])
        return Peak(a,m+1,h,n);
}
int main()
{
    int n,i,l,h,a[100],x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l=0;
    h=n-1;
    x=Peak(a,l,h,n);
    cout<<a[x];
    return 0;
}

