//Spiral Print of a 2-D array (anti-clockwise)

#include<iostream>
using namespace std;
int main()
{
    int m,n,x[10][10],i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cin>>x[i][j];
    }
    int a=0,b=n-1,c=m-1,d=0;
    while(a<=c && d<=b)
    {
        for(i=a;i<=c;i++)
        {
            if(x[i][d]!=-1)
            cout<<x[i][d]<<", ";
            x[i][d]=-1;
        }
        d++;
        for(j=d;j<=b;j++)
        {
            if(x[c][j]!=-1)
            cout<<x[c][j]<<", ";
            x[c][j]=-1;
        }
        c--;
        for(i=c;i>=a;i--)
        {
            if(x[i][b]!=-1)
            cout<<x[i][b]<<", ";
            x[i][b]=-1;
        }
        b--;
        for(j=b;j>=d;j--)
        {    
            if(x[a][j]!=-1)
            cout<<x[a][j]<<", ";
            x[a][j]=-1;
        }
        a++;
    }
    cout<<"END";
    return 0;
}