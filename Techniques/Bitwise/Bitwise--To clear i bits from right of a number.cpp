// To clear i bits from right of a number

#include<iostream>
using namespace std;

int clear_i_Bits_from_left(int n,int i)
{   
    int mask=( (~0) << i);
    n=n&mask;
    return n;
}

int main()
{
    // i = no of bits to be cleared from left
    
    int n,i;
    cin>>n>>i;
    cout<<clear_i_Bits_from_left(n,i);
    return 0;
}