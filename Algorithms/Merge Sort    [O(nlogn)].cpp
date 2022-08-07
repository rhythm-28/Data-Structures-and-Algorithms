//Merge Sort
#include<iostream>
using namespace std;
void Merge(int x[],int l,int mid,int h)
{
    int i=0,j=0,k=l,m=0,n=0,a[100],b[100],e;
    for(e=l;e<=mid;e++)
    {
        a[m]=x[e];
        m++;
    }
    for(e=mid+1;e<=h;e++)
    {
        b[n]=x[e];
        n++;
    }
    while(i!=m && j!=n)
    {                   
        if(a[i]<=b[j])
        {
            x[k]=a[i];
            k++;
            i++;
        }
        else if(a[i]>b[j])
        {
            x[k]=b[j];
            k++;
            j++;
        }
    }
    while(i!=m)
    {
        x[k]=a[i];
        k++;
        i++;
    }
    while(j!=n)
    {
        x[k]=b[j];
        k++;
        j++;
    }
}
void MergeSort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}
int main()
{
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    MergeSort(a,0,n-1);
    for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}