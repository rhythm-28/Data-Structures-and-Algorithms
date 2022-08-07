// 0-1 Knapsack Problem (using Biwtise operators)

#include<iostream>
#include<math.h>
using namespace std;

int profit=0;
int filter(int i,int price[],int weights[],int capacity)
{
    int j=0,last_bit,sum=0,weight=0;
    while(i>0)
    {
        last_bit=(i&1);
        if(last_bit==1)
        {
            sum+=price[j];
            weight+=weights[j];
        }
        j++;
        i=i>>1;
    }

    if(sum>profit && weight<=capacity)
    profit=sum;

    return profit;
}

int find_Subsets(int price[],int weights[],int n,int capacity)
{
    int profit;
    for(int i=0;i<pow(2,n);i++)
    profit=filter(i,price,weights,capacity);

    return profit;
}

int main()
{
    int i,price[100],weights[100],n,capacity;

    cin>>n;
    for(i=0;i<n;i++)
    cin>>price[i];

    for(i=0;i<n;i++)
    cin>>weights[i];

    cin>>capacity;

    cout<<"profit="<<find_Subsets(price,weights,n,capacity);

    return 0;
}