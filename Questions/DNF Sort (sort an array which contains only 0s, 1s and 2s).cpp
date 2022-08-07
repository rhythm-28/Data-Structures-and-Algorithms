// DNF Sort
// sort an array which contains only 0s, 1s and 2s

#include<iostream>
#include<algorithm>
using namespace std;

void DNF_Sort(int a[],int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
        mid++;
        else
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main()
{
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    DNF_Sort(a,n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}