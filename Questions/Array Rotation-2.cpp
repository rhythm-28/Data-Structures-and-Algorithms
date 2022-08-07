//Rotating an Array 
// [O(n)]

#include<iostream>
#include<vector>
using namespace std;
void Reverse(int  a[],int b,int c)
{
    int i,temp;
    for(i=b;i<(c/2);i++)
    {
        temp=a[i];
        a[i]=a[c-i-1];
        a[c-i-1]=temp;
    }
}
int main()
{
    int n,y,i,k,a[10];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    Reverse(a,0,k+1);
    Reverse(a,k+2,n);
    Reverse(a,0,n);
    for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}