// To find no of ways one can reach top of a ladder from ground if he can jump a maximum of k steps at a time
// no of steps on ladder = n

#include<iostream>
using namespace std;

int find_ways(int n,int k)
{
	if(n<0)
    	return 0;
    
	if(n==1)
    	return 1;
	    
    else
    {
        int ans=0,i;
        for(i=1;i<=k;i++)
        ans+=find_ways(n-i,k);
        return ans;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<find_ways(n,k);
    return 0;
}