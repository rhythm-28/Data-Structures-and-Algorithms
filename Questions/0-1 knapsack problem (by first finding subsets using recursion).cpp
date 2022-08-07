// 0-1 knapsack problem (by first finding subsets using recursion)

#include<iostream>
using namespace std;

int profit=0;

void find_subsets(int prices[],int weights[],int output[],int i,int j,int n,int capacity)
{
    // base case
    // reached end of array
    if(i==n)
    {
        int sum=0,weight=0;
        int m = *(&output + 1) - output;
        for(int k=0;k<m;k++)
        {
            sum+=prices[k];
            weight+=weights[k];
        }
        if(sum>profit && weight<=capacity)
        profit=sum;
    }

    //recursive case
    else
    {
        // include element at (i)th index
        output[j]=prices[i];
        find_subsets(prices,weights,output,i+1,j+1,n,capacity);

        // exclude element at (i)th index
        find_subsets(prices,weights,output,i+1,j,n,capacity);
    }
}

int main()
{
    int n,i,prices[100],weights[100],output[100],capacity;

    cin>>n;
    for(i=0;i<n;i++)
    cin>>prices[i];

    for(i=0;i<n;i++)
    cin>>weights[i];

    cin>>capacity;

    find_subsets(prices,weights,output,0,0,n,capacity);
    cout<<profit;
    return 0;
}