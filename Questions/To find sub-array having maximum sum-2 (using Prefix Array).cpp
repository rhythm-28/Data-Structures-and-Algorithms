// To find sub-array having maximum sum
// O(n^2) 

#include<iostream>
using namespace std;
int main()
{
    int n,a[10],csum[10],k,sum=0,max=0,l,m,i;
    int strtPnt,endPnt;
    cin>>n;

    for(i=0;i<n;i++)
    cin>>a[i];

    csum[0]=a[0];
    for(i=1;i<n;i++)
    csum[i]=csum[i-1]+a[i];

    for(strtPnt=0;strtPnt<n;strtPnt++)
    {
        for(endPnt=strtPnt;endPnt<n;endPnt++)
        {
            if(strtPnt!=0)
            sum=csum[endPnt]-csum[strtPnt-1];
            else
            sum=csum[endPnt];
            
            if(sum>=max)
            {
                max=sum;
                l=strtPnt;
                m=endPnt;
            }
            sum=0;
        }
    }
    cout<<max<<endl;
    for(i=l;i<=m;i++)
    cout<<a[i]<<" ";
    return 0;
}