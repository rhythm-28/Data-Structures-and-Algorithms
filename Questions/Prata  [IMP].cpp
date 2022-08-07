// Prata

#include<iostream>
using namespace std;

bool valid(int time,int p,int a[],int n)
{
    int x,i,sum,j;
    x=0;
    for(i=0;i<n;i++)
    {
        sum=0,j=1;
        while(sum<=time)
        {
            sum+=(a[i]*j);
            j++;
        }
        j--;
        sum-=(a[i]*j);
        x+=(j-1);
    }
    if(x>=p)
    return true;
    else 
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t,p,n,i,a[55],max_time,low,high,mid,ans;
    cin>>t;
    while(t--)
    {
        cin>>p;
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];

        max_time=a[n-1]*(p*(p+1))/2;
        low=0,high=max_time;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(valid(mid,p,a,n))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}