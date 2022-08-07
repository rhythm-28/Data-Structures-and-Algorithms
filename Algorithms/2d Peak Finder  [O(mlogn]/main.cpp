// 2-D Peak Finder (only one)
/*
abcd
efgh
ijkl
mnop
if if f>=b & f>=e & f>=j & f>=g  => f is a peak
*/

#include <iostream>

using namespace std;

int Peak2D(int a[][50], int max ,int j,int m,int n)
{
    int c,d;
    for(int i=0;i<m;i++)
    {
        if(max<=a[i][j])
        {
            max=a[i][j];
            c=i;
            d=j;
        }
    }

    if(j==0 || j==n-1)
        return max;

    else if((max>=a[c][d-1] && max>=a[c][d+1]))
        return max;

    else if(max < a[c][d-1])
        return Peak2D(a,a[c][d-1],d-1,m,n);

    else if(max < a[c][d+1])
        return Peak2D(a,a[c][d+1],d+1,m,n);
}
int main()
{
    int x,m,n,i,j,a[50][50],max;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    max=a[m/2][n/2];
    j=n/2;
    x=Peak2D(a,max,j,m,n);
    cout<<x;
    return 0;
}
