// 0-1 Knapsack Problem (using recursion)

#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int find_profit(int prices[],int weights[],int n,int crnt_cpcty)
{
    // base case
    if(n==0 || crnt_cpcty==0)
    return 0;
    
    // recursive case
    int inc=0,exc=0;

    // include current element
    if(weights[n-1]<=crnt_cpcty)
    inc=prices[n-1]+find_profit(prices,weights,n-1,crnt_cpcty-weights[n-1]);

    // exclude current element
    exc=find_profit(prices,weights,n-1,crnt_cpcty);

    return max(inc,exc);
}

int main()
{
    int i,prices[100],weights[100],n,capacity;

    cin>>n;
    for(i=0;i<n;i++)
    cin>>prices[i];

    for(i=0;i<n;i++)
    cin>>weights[i];

    cin>>capacity;

    cout<<"profit="<<find_profit(prices,weights,n,capacity);

    return 0;
}