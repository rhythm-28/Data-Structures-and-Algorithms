// Staircase Search
// For searching an element in a 2-D array
// O(n)

#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>m>>n;
    int a[10][10];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    int b;
    cin>>b;
    i=0,j=n-1;
    while(i<m)
    {
        if(a[i][j]==b)
        {
            cout<<i<<" "<<j;
            break;
        }
        else if(a[i][j]<b)
        i++;
        else
        j--;
    }
    return 0;
}