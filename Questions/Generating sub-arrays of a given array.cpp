/* Generating sub-arrays of a given array
 A sub-array is a continuous part of an array*/ 

#include<iostream>
using namespace std;
int main()
{
    int n,a[10],i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=i;k<=j;k++)
                cout<<a[k];
            cout<<endl;
        }
    }

    return 0;
}