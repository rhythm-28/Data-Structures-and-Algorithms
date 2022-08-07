// Use of Comparators

#include<iostream>
#include <algorithm>

using namespace std;

bool compare(int a,int b)
{
    return a<b;
    /* returns true when a<b
    & false when a>b */ 
}

void Bubble_sort(int a[],int n,bool (&cmp) (int a,int b))
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(cmp(a[j],a[j+1]))
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,i,j,temp=0,a[100];

    cout<<"Enter size of array: \n";
    cin>>n;

    cout<<"Enter array elements: \n";
    for(i=0;i<n;i++)
    cin>>a[i];
    
    // User-Defined Function of sort with comparator
    Bubble_sort(a,n,compare);

    // In-Built sort with comparator 
    sort(a,a+n,compare);

    cout<<"The sorted array is: \n";
    for(i=0;i<n;i++)
    cout<<a[i];

    return 0;
}
