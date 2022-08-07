// Given an array of integers,find the minimum number of steps required to make the elements in array equal
// (atmost 1 element can be transferred to both adjacent neighbours)

#include<iostream>
#include<algorithm>
using namespace std;

int load_balancer(int n,int a[])
{
    int load=0,i;
    for(i=0;i<n;i++)
    load+=a[i];

    if(load%n!=0)
    return -1;

    else
    {
        load=load/n;
        int ans,max_load,diff=0;
        for(i=0;i<n;i++)
        {
            diff+=(a[i]-load);
            ans=abs(diff);
            max_load=max(ans,max_load);
        }
        return max_load;
    }
}

int main()
{
    int i,n,a[10000];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<load_balancer(n,a)<<endl;

    return 0;
}