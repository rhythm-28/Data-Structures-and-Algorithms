// To check if an array contains a sub-array having sum=0 or not

#include<iostream>
#include<unordered_map>
using namespace std;

bool check_sum(int n,int a[])
{
    int i,sum=0;
    unordered_map<int,bool> um;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        
        if(sum==0)
        return true;
        
        auto it=um.find(sum);
        if(it!=um.end())
        return true;

        um[sum]=false;
    }
    return false;
}

int main()
{
    int n,a[10],csum=0,k,sum=0,max=0,l,m,i;
    int strtPnt,endPnt;
    cin>>n;

    for(i=0;i<n;i++)
    cin>>a[i];

    if(check_sum(n,a))
    cout<<"true";
    else
    cout<<"false";
  
    return 0;
}