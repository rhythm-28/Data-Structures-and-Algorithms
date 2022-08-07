// Wave Print of a 2-D array

#include<iostream>
using namespace std;
int main()
{
    int m,n,a[10][10],i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    for(j=0;j<n;j++)
    {
        if(j%2==0)
        {
            //Top To Bottom Direction
            for(i=0;i<m;i++)
            cout<<a[i][j]<<" ";
        }
        else
        {
            //Bottom To Top Direction
            for(i=m-1;i>=0;i--)
            cout<<a[i][j]<<" ";
        }
    }
    return 0;
}