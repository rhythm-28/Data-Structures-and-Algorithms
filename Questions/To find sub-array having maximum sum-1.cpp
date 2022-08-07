// To find sub-array having maximum sum
// O(n^3) 

#include<iostream>
using namespace std;
int main()
{
    int n,a[10],k,sum=0,max=0,l,m,i;
    int strtPnt,endPnt;
    cin>>n;

    for(i=0;i<n;i++)
    cin>>a[i];

    for(strtPnt=0;strtPnt<n;strtPnt++)
    {
        for(endPnt=strtPnt;endPnt<n;endPnt++)
        {
            for(k=strtPnt;k<=endPnt;k++)
            {
                sum+=a[k];
            }
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