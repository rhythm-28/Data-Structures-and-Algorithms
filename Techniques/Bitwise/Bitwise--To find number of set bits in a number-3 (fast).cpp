// To find number of set bits in a number
// O(no of set bits)

#include<iostream>
#include<math.h>

using namespace std;

int countBits(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        ans++;
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