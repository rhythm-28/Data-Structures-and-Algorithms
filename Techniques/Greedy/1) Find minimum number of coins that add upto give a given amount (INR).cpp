// Find minimum number of coins that add upto give a given amount (INR)

#include<iostream>
#include<algorithm>
using namespace std;

int make_change(int a[],int n,int money)
{
    int count=0,idx,x;
    while(money!=0)
    {
        idx=upper_bound(a,a+n,money)-a;
        money=money-a[idx-1];
        count++;
    }
    
    return count;
}

int main()
{
    int a[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(a)/sizeof(int);
    int money;
    cin>>money;
    cout<<make_change(a,n,money);
    return 0;
}