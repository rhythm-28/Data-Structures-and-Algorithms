// To make array as negative numbers on left side and positive numbers on right side of an array

#include<iostream>
using namespace std;

void Partition(int a[],int n)
{
    int i,j,temp;
    i=0;
    j=n-1;
    while(i<j)
    {
        while(a[i]<0){
        i++;
        }

        while(a[j]>=0){
        j--;
        }

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

int main()
{
    int n,i,a[10];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    Partition(a,n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}