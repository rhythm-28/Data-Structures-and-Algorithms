// Print the sum of the submatrix which has the maximum sum in a row and column wise sorted matirx 
// O(n^2)

#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int m,n,i,j;
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
    for(i=m-1;i>=0;i--)
    {
        for(j=n-2;j>=0;j--)
        a[i][j]+=a[i][j+1];
    }
    for(j=n-1;j>=0;j--)
    {
        for(i=m-2;i>=0;i--)
        a[i][j]+=a[i+1][j];
    }
    int max=INT_MIN;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]>=max)
            max=a[i][j];
        }
    }
    cout<<"max sum of sub-matrix is "<<max;
    return 0;
}
