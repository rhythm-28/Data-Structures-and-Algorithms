// To find length of longest sub-array having sum=k

#include<iostream>
#include<unordered_map>
using namespace std;

int check_sum(int n,int a[],int k)
{
    int i,sum=0,length=0,max=1;
    unordered_map<int,int> um;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        
        if(sum==k)
        {
            length=i+1;
            if(length>max)
            max=length;
        }
        
        if(um.find(sum-k)!=um.end())
        {
            length=i-um[sum-k];
            if(length>max)
            max=length;
        }

        um[sum]=i;
    }
    return max;
}

int main()
{
    int n,a[1000],i,k;
    cin>>n>>k;

    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<check_sum(n,a,k);
  
    return 0;
}