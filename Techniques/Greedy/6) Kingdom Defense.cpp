// Kingdom Defense

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int w,h,n,i,x[50000],y[50000];
    cin>>w>>h>>n;
    for(i=0;i<n;i++)
    cin>>x[i]>>y[i];

    sort(x,x+n);
    sort(y,y+n);

    int length,breadth;
    length=x[0]-1;
    breadth=y[0]-1;

    for(i=1;i<n;i++)
    {
        length=max(length,x[i]-x[i-1]-1);
        breadth=max(breadth,y[i]-y[i-1]-1);
    }

    length=max(length,w-x[n-1]);
    breadth=max(breadth,h-y[n-1]);

    cout<<length*breadth;

    return 0;
}