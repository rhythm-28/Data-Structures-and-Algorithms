// union of two un-sorted arrays
// O(m*n)

#include<iostream>
using namespace std;
int main()
{
    int n,a[20],m,b[20],i,j,k,c[50],x;
    
    // set-1
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    //set-2
    cin>>m;
    for(i=0;i<m;i++)
    cin>>b[i];

    for(k=0;k<n;k++)
    c[k]=a[k];
    k=n;

    for(i=0;i<m;i++)
    {
        x=-1;
        for(j=0;j<n;j++)
        {
            if(b[i]==c[j])
            {
                x=0;
                break;
            }
        }
        if(x==-1)
        {
            c[k]=b[i];
            k++;
        }
    }

    for(i=0;i<k;i++)
    cout<<c[i]<<" ";

    return 0;
}