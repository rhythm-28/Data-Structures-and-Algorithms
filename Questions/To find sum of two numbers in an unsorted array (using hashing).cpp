/* To find which two elements in an
unsorted array add to provide the given sum
[ O(max)/ O(n) ]
*/
#include<iostream>
using namespace std;
int main()
{
    int n,a[100],i,c,max,*b,sum;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>sum;
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    b=new int[max];
    for(i=0;i<=max;i++)
    b[i]=0;
    for(i=0;i<n;i++)
    {
        if(b[sum-a[i]]!=0 && a[i]<sum)
        cout<<a[i]<<" "<<sum-a[i]<<endl;
        b[a[i]]++;
    }
    return 0;
}