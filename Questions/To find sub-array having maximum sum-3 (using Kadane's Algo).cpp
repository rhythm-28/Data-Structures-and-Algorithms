// To find sub-array having maximum sum
// Kadane's Algorithm
// O(n) 

#include<iostream>
using namespace std;
int main()
{
    int n,a[10],sum=0,max=0,i;
    cin>>n;

    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    {   
        if(sum<0)
        sum=0;

        else
        sum+=a[i];
        
        if(sum>=max)
        max=sum;
    }

    cout<<max<<endl;
    return 0;
}