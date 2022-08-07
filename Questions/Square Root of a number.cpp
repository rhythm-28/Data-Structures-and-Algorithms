// Square Root of a number
// O(logn)

#include<iostream>
using namespace std;

float Square_Root(int n,int p)
{
    int l=0,h=n,mid;
    float ans;
    while(l<=h)
    {
        mid=(l+h)/2;

        // For perfect square
        if((mid*mid)==n)
        return mid;

        else if((mid*mid)>n)
        h=mid-1;

        else
        {
            // If not a perfect square
            ans=mid;
            l=mid+1;
        }
    }

    // If not a perfect square
    float inc=0.1;

    // total= 10*p times

    while(p--)
    {
        // will work max 10 times
        while((ans*ans)<n)
        {
            ans+=inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
}

int main()
{
    // p is no of decimal places
    int n,p;
    cin>>n;
    cin>>p;
    cout<<Square_Root(n,p);
    return 0;
}