// To find numbers (from a given array) which add up to provide a given sum

#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

void find_combinations(int inp[],int out[],int i,int j,int n,int crnt_sum,set<vector<int>> &s)
{
    // base case
    if(i==n || crnt_sum==0)
	{
		if(crnt_sum==0)
        {
            vector<int> temp;
            for(i=0;i<j;i++)
            temp.push_back(out[i]);
            s.insert(temp);
        }
		return;
	}
    
    // recursive case

    // include current element
    if(inp[i]<=crnt_sum)
	{
		out[j]=inp[i];
		find_combinations(inp,out,i+1,j+1,n,crnt_sum-inp[i],s);
	}

    // exclude current element
    find_combinations(inp,out,i+1,j,n,crnt_sum,s);
}

int main()
{
    int i,inp[1000],out[1000],n,sum;
	set<vector<int>> s;

    cin>>n;
    for(i=0;i<n;i++)
    cin>>inp[i];
    cin>>sum;

	sort(inp,inp+n);
    find_combinations(inp,out,0,0,n,sum,s);

    for (auto k:s)
	{
		for(int j:k)
		cout << j << " ";
		cout << endl;
	}

    return 0;
}