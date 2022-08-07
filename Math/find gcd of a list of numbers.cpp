// find gcd of a list of numbers
// time complexity : O(n*log(m))
// m is smallest element of array

#include<bits/stdc++.h>

using namespace std;

#define lli long long int

lli gcd(lli a,lli b)
{
    if(a==0)
    return b;
    
    return gcd(b%a,a);
}

lli gcd_of_list(lli n,vector<lli> a)
{
    lli i,ans=a[0];
    for(i=0;i<n;i++)
        ans=gcd(ans,a[i]);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    lli i,n,y;
    vector<lli> a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        a.push_back(y);
    }
    cout<<gcd_of_list(n,a);
    return 0;
}
