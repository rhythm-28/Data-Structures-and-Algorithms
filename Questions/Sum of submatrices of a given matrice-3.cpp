// Sum of submatrices of a given matrice 
// Finding contribution of each element in final sum
// Find how many submatrices each element belongs to
// O(n^2)

#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j,x,y,sum=0;
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
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            x=(i+1)*(j+1);
            y=(m-i)*(n-j);
            sum+=(a[i][j]*x*y);
        }
    }
    cout<<"sum is "<<sum;
    return 0;
}
