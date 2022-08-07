// intersection of two sorted arrays
// O(m+n)

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

    i=j=k=0;
    while(i!=m && j!=n)
    {
        if(a[i]<b[j])
        i++;

        else if(a[i]>b[j])
        j++;

        else
        {
            c[k]=a[i];
            k++;
            i++;
            j++;
        }
    }

    for(i=0;i<k;i++)
    cout<<c[i]<<" ";

    return 0;
}