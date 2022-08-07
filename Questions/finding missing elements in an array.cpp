// Finding Missing elements in an array

#include<iostream>

using namespace std;
int main()
{
    int n,a[20],i,diff,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    diff=a[0];
    for(i=0;i<n;i++)
    {
        if( (a[i]-i) != diff)
        {
            for(j=diff;j<a[i]-i;j++)
            {
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
   
    return 0;
}