// To find number of set bits in a number
// O(logn)

#include<iostream>
#include<math.h>

using namespace std;

int countBits(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        n=(n>>1);
    }
    return ans;
}

int main()
{
    int n,i;
    cin>>n;
    cout<<countBits(n);
    return 0;
}