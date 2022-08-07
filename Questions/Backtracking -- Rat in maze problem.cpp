// Backtracking -> Rat in maze problem

#include<iostream>
using namespace std;

char rat_in_maze(char inp[10][10],char out[10][10],int i,int j,int m,int n)
{
    // base case
    if(i==m && j==n)
    {
        out[i][j]='1';
        for(int a=0;a<=m;a++)
        {
            for(int b=0;b<=n;b++)
            cout<<out[a][b];
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    // out of maze condition
    if(i>m || j>n)
    return false;

    // blockade condition
    if(inp[i][j]=='X')
    return false;


    // recursive case
    
    // assuming solution exists
    out[i][j]='1';

    bool right=rat_in_maze(inp,out,i,j+1,m,n);
    bool down=rat_in_maze(inp,out,i+1,j,m,n);

    // backtracking
    out[i][j]='0';

    if( (right==true) || (down==true) )
    return true;

    else 
    return false;
}

int main()
{
    char out[10][10]={"0000","0000","0000","0000"};
    int m,n;
    char inp[10][10]={"0000",
                      "0XX0",
                      "0X00",
                      "0X00" };
    m=4,n=4;
    /*
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>inp[i][j];
    }
    */
    bool ans=rat_in_maze(inp,out,0,0,m-1,n-1);
    if(ans==false)
    cout<<"no solution";
    return 0;
}