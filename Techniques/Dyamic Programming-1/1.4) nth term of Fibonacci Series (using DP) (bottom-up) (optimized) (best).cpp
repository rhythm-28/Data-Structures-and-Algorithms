// nth term of Fibonacci Series (using DP)
// Bottom-Up Approach
// Time: O(n)
// Space : O(1)

#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)
    return n;
    
    int a=0,b=1,c;

    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }

    return c;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}