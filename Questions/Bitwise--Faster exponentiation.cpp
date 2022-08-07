// Faster exponentiation
// O(logn)

#include<iostream>
using namespace std;

int find_ans(int a,int b)
{
    int last_bit,ans=1;
    while(b>0)
    {
        last_bit=b&1;
        if(last_bit==1)
        ans=ans*a;
        b=b>>1;
        a=a*a;
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<find_ans(a,b);   
    return 0;
}