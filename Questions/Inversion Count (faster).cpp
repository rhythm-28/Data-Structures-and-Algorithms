//Inversion Count 
// O(nlogn)
#include<iostream>
using namespace std;
int Merge(int x[],int l,int mid,int h)
{
    int i=0,j=0,k=l,m=0,n=0,a[100],b[100],e,count=0;
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
            count+=(m-i);
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
    return count;
}
int InversionCount(int a[],int l,int h)
{
    int mid,x=0,y=0,z=0;
    if(l<h)
    {
        mid=(l+h)/2;
        x=InversionCount(a,l,mid);
        y=InversionCount(a,mid+1,h);
        z=Merge(a,l,mid,h);
    }
    return x+y+z;
}
int main()
{
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<InversionCount(a,0,n-1);
    return 0;
}