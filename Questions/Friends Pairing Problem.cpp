// Friends Pairing Problem
// Find no of ways in which a group of friends can go to a party if each guy can go either alone or in a pair

#include<iostream>
using namespace std;

int find_ways(int n)
{
    if(n<=1)
    return 1;

    else
    return find_ways(n-1) + (n-1)*find_ways(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<find_ways(n);
    return 0;
}