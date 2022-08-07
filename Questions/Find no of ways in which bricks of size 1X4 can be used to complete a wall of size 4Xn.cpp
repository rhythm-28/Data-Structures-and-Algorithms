// Find no of ways in which bricks of size 1X4 can be used to complete a wall of size 4Xn
//(bricks can be placed both vertically and horizontally) 

#include<iostream>
using namespace std;

int find_ways(int n)
{
    if(n<=3)
    return 1;
    else
    return find_ways(n-1)+find_ways(n-4);
}

int main()
{
    int n;
    cin>>n;
    cout<<find_ways(n);
    return 0;
}