// To search for an element in a 2-D array
// O(m*logn)

#include<iostream>
using namespace std;
int main()
{
    int m,n,a[10][10],i,j,l,h,b,mid;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    cin>>b;
    for(i=0;i<m;i++)
    {
        l=0,h=n-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(a[i][mid]==b)
            {
                cout<<i<<" "<<mid;
                break;
            }
            else if(b>a[i][mid])
            l=mid+1;
            else
            h=mid-1;
        }
        if(a[i][mid]==b)
        break;
    }
    return 0;
}