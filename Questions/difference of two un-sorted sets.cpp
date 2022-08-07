/* 
difference of two un-sorted sets
(elements present in A but not in B = A-B)
*/
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

    for(i=0;i<n;i++)
    {
        x=-1;
        for(j=0;j<m;j++)
        {
            if(b[j]==a[i])
            {
                x=0;
                break;
            }
        }
        if(x==-1)
        {
            c[k]=a[i];
            k++;
        }
    }

    for(i=0;i<k;i++)
    cout<<c[i]<<" ";

    return 0;
}