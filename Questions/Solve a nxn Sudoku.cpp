// Solve a nxn Sudoku

#include<iostream>
#include<cmath>
using namespace std;

bool valid(int grid[][9],int i,int j,int k, int n)
{   
    int a,b;
    // check for row
    for(b=0;b<n;b++)
    {
        if(grid[i][b]==k)
        return false;
    }

    // check for column
    for(a=0;a<n;a++)
    {
        if(grid[a][j]==k)
        return false;
    }

    // check for subgrid
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;

    for(a=sx;a<sx+rn;a++)
    {
        for(b=sy;b<sy+rn;b++)
        {
            if(grid[a][b]==k)
            return false;
        }
    }

    // if digit is not present anywhere, that means digit can be placed there
    return true;
}

bool sudoku_solver(int grid[][9],int i,int j,int n)
{
    // base case
    if(i==n)
    {
        // print the array
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }

    // recursive case

    // if reached end of row, call for next row
    if(j==n)
    return sudoku_solver(grid,i+1,0,n);

    // check if position is empty
    if(grid[i][j]==0)
    {
        // check which digit can be placed there
        for(int k=1;k<=9;k++)
        {
            if(valid(grid,i,j,k,n)==true)
            {
                // place the digit there
                grid[i][j]=k;

                // and call for next
                bool ans=sudoku_solver(grid,i,j+1,n);

                if(ans==true)
                return true;
            }
        }
        // backtracking
        grid[i][j]=0;
        return false;
    }

    // if position not empty
    else
    return sudoku_solver(grid,i,j+1,n);
}

int main()
{
    /*int grid[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
                  };
    
    */
    int n,grid[9][9];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>grid[i][j];
    }
    sudoku_solver(grid,0,0,n);
    return 0;
}