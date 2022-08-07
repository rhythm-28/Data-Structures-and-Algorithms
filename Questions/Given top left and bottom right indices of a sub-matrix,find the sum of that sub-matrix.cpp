// Given top left and bottom right indices of a sub-matrix,find the sum of that sub-matrix 
// O(n^2)

#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j,q;
    int x1,x2,y1,y2,ans=0;
    cin>>m>>n;
    int** a;
    a=new int*[m];
    for(i=0;i<m;i++)
    a[i]=new int[n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }

    // Creating prefix matrix
    for(i=0;i<m;i++)
    {
        for(j=1;j<n;j++)
        a[i][j]+=a[i][j-1];
    }
    for(j=0;j<n;j++)
    {
        for(i=1;i<m;i++)
        a[i][j]+=a[i-1][j];
    }

    //No of queries
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        ans=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
        cout<<ans<<endl;
    }
    return 0;
}
