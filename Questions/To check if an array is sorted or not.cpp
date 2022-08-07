// To check if an array is sorted or not

#include<iostream>
using namespace std;
bool Check(int a[],int n)
{  
    int i;
    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        return false;
    }
    return true;
}
int main()
{
    int n,i,a[10];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    int ans=Check(a,n);
    if(ans)
    cout<<"sorted";
    else
    cout<<"not sorted";
    return 0;
}