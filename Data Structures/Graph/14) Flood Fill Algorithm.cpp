// Flood Fill Algorithm

#include<iostream>
using namespace std;

void flood_fill(char a[][100],int i,int j,char ch,char colour,int n,int m)
{
    // goes out of bounds
    if(i<0 || j<0 || i>=n || j>=m)
    return ;

    // reaches a place where paint is not to be done
    if(a[i][j]!=ch)
    return ;

    // reaches a place where paint is already dropped 
    if(a[i][j]==colour)
    return ;

    a[i][j]=colour;
    flood_fill(a,i-1,j,ch,colour,n,m);
    flood_fill(a,i,j-1,ch,colour,n,m);
    flood_fill(a,i+1,j,ch,colour,n,m);
    flood_fill(a,i,j+1,ch,colour,n,m);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i,j,m,n;
    char a[100][100],ch,colour;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>a[i][j];
    }
    // point where paint is dropped
    cin>>i>>j;

    // ch => character to be replaced
    cin>>ch>>colour;
    flood_fill(a,i,j,ch,colour,n,m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<a[i][j];
        cout<<endl;
    }

    return 0;
}