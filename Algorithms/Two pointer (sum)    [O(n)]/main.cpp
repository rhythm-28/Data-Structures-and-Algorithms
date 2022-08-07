// Two Pointer Algorithm

/*
To find which two elements in the
array add to provide the given sum
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
            cout<<a[i]<<" "<<a[j];
            break;
        }
        else if((a[i]+a[j])<sum)
        i++;
        else
        j--;
    }
    return 0;
}
