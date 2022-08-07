// In a given list of numbers, find the number which doesn't appear twice

#include<iostream>
using namespace std;
int main()
{
    int n,i,x=0,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y;
        x=x^y;
    }
    cout<<x;
    return 0;
}