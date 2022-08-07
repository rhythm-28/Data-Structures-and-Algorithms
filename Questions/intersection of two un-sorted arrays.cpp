// intersection of two un-sorted arrays
// O(m*n)

#include<iostream>
using namespace std;
int main()
{
    int n,a[20],m,b[20],i,j,k=0,c[50],x;
    
    // set-1
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    //set-2
    cin>>m;
    for(i=0;i<m;i++)
    cin>>b[i];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                c[k]=a[i];
                k++;
            }
        }
    }

    for(i=0;i<k;i++)
    cout<<c[i]<<" ";

    return 0;
}