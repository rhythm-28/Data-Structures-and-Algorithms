// To find maximum sum of k consecutive elements 
// Window Sliding Technique
// O(n)

#include<iostream>
using namespace std;
int main()
{
    int n,i,a[100],csum=0,max,k;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    for(i=0;i<k;i++)
    csum+=a[i];
    max=csum;
    for(i=k;i<n;i++)
    {
        csum=csum+a[i]-a[i-k];
        if(csum>max)
        max=csum;
    }
    cout<<max;
    return 0;
}