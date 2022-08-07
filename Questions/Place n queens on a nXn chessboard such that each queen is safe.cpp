// Place n queens on a nXn chessboard such that each queen is safe 

#include<iostream>
using namespace std;

bool safe(int i,int j,int board[][10],int n)
{
    // Check for left diagonal
    int a=i,b=j;
    while(a>=0 && b>=0)
    {
        if(board[a][b]==1)
        return false;

        a--;
        b--;
    }
    
    // Check for upper column 
    for(a=i;a>=0;a--)
    {
        if(board[a][j]==1)
        return false;
    }

    // Check for right diagonal
    a=i,b=j;
    while(a>=0 && b<=n-1)
    {
        if(board[a][b]==1)
        return false;

        a--;
        b++;
    }

    // if safe
    return true;
}

bool N_Queen(int n,int i,int board[][10])
{
    // base case
    if(i==n)
    {
        // print the arrangement
        int j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]==1)
                cout<<"Q ";
                else
                cout<<"_ ";
            }
            cout<<endl;
        }
        // as solution is possible
        return true;
    }

    // recursive case
    for(int j=0;j<n;j++)
    {
        if(safe(i,j,board,n)==true)
        {
            // assuming 
            board[i][j]=1;

            // call for next row
            bool ans=N_Queen(n,i+1,board);

            //backtracking
            if(ans==false)
            board[i][j]=0;

            else
            return true;
        }
    }
    // if reached end of row and not got a safe position, go to previous row 
    return false;
}

int main()
{
    int n,board[10][10]={0};
    cin>>n;
    N_Queen(n,0,board);
    return 0;
}