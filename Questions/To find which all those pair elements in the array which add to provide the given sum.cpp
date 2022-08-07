/*
To find which all those pair elements in
the array which add to provide the given sum
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,n,sum,a[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cin>>sum;
    i=0,j=n-1;
    while(i<j)
    {
        if((a[i]+a[j])==sum)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
        }
        else if((a[i]+a[j])<sum)
        i++;
        else
        j--;
    }
    return 0;
}
