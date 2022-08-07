// Given length of n chopsticks, find maximum number of usable pairs with maximum difference between their lengths as d

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int n,d,y,i,count=0;
	vector<int> v;
	cin>>n>>d;
	for(i=0;i<n;i++)
	{
	    cin>>y;
	    v.push_back(y);
	}
	sort(v.begin(),v.end());
	i=0;
	while(i<n-1)
	{
	    if(v[i+1]-v[i]<=d)
	    {
	        i=i+2;
	        count++;
	    }
	    else
	    {
	        i++;
	    }
	}
	cout<<count;
	return 0;
}
