// In a list of numbers (where each number appears twice) find the 2 unique numbers

#include<iostream>
using namespace std;

// Find the location at which bit is set
int find_location(int n)
{
    int i=0;
    while(n>0)
    {
        if((n&1)==1)
        break;
        n=n>>1;
        i++;
    }
    return i;
}

// Check if bit is 0 or 1
int getBit(int n,int i)
{
    int mask=(1<<i);
    int bit= (mask&n);
    if(bit==0)
    return 0;
    else
    return 1;
}

void find_Ans(int a[],int n)
{
    int i,pos,x=0,y,b=0,c;
    for(i=0;i<n;i++)
    x=x^a[i];

    // Position at which bit is set
    pos=find_location(x);

    // Find all such numbers who have a bit set at position pos
    for(i=0;i<n;i++)
    {
        y=getBit(a[i],pos);

        // XOR of all such numbers 
        if(y==1)
        b=b^a[i];
    }

    // b is one of the unique numbers
    // To find the other unique number, take its XOR with x
    c=b^x;

    if(b<c)
    cout<<b<<" "<<c;
    else
    cout<<c<<" "<<b;
}

int main()
{
    int n,i,a[10];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    find_Ans(a,n);   
    return 0;
}