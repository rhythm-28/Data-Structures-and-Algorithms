// Quick Sort

#include<iostream>
using namespace std;
int Partition(int a[],int l,int h)
{
    int i,j,pivot,temp;
    i=l,j=h;
    while(i<j)
    {
        pivot=a[l];
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}
void QuickSort(int a[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=Partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}
int main()
{
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    QuickSort(a,0,n-1);
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;
    return 0;
}