// To find no of ways one can reach top of a ladder from ground if he can jump a maximum of 3 steps at a time
// no of steps on ladder = n

#include<iostream>
using namespace std;

int find_ways(int n)
{
   if(n<0)
    	return 0;
    
	if(n==1)
    	return 1;
    
    else
    return find_ways(n-1)+find_ways(n-2)+find_ways(n-3);
}

int main()
{
    int n;
    cin>>n;
    cout<<find_ways(n);
    return 0;
}