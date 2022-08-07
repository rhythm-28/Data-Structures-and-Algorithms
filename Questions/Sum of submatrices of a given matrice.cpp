// Sum of submatrices of a given matrice 
// O(n^6)

#include<iostream>
using namespace std;
int main()
{
    int** a;
    int m,n,i,j;
    int x1,x2,y1,y2,ans=0;
    cin>>m>>n;
    a=new int*[m];
    for(i=0;i<m;i++)
    a[i]=new int[n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    for(x1=0;x1<m;x1++)
    {
        for(y1=0;y1<n;y1++)
        {
            for(x2=x1;x2<m;x2++)
            {
                for(y2=y1;y2<n;y2++)
                {
                    for(i=x1;i<=x2;i++)
                    {
                        for(j=y1;j<=y2;j++)
                        ans+=a[i][j];
                    }
                }
            }
        }
    }
    cout<<"sum is "<<ans;
    return 0;
}
