// Given n white & n black dots, find minimum wire length required to connect each white node with 1 black dot

#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,a[100],b[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    cin>>b[i];

    sort(a,a+n);
    sort(b,b+n);

    int sum=0;
    for(i=0;i<n;i++)
    sum+=abs(a[i]-b[i]);
    cout<<sum;

    return 0;
}