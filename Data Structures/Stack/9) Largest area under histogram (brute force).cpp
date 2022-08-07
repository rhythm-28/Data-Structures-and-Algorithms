// Largest area under histogram
// O(n^2)

#include<climits>
#include<iostream>
using namespace std;

int histogram(int a[],int n)
{
    int min,area,i,j,ans=0;
    for(i=0;i<n;i++)
    {
        min=INT_MAX;
        for(j=i;j<n;j++)
        {
            if(a[j]<min)
            min=a[j];
        }
        area=(j-i+1)*min;
        if(area>ans)
        ans=area;
    }
    return ans;
}

int main()
{
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<histogram(a,n);
    return 0;
}