// Find minimum number of coins required to form a certain amount

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int money,i,count=0;
    cin>>money;
    while(money!=0)
    {
        i=upper_bound(coins,coins+10,money)-coins-1;
        money=money-coins[i];
        count++;
    }
    cout<<count;
    return 0;
}