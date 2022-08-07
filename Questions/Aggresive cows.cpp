// Aggresive cows/ John & his cows
// O(tlogn)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int t,n,c,j,low,high,mid,cows,k,best,prevPos;
vector<int> a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>c;
		for(j=0;j<n;j++)
{
cin>>y;
a.push_back(y);
}
		sort(a,a+n);
		low=1;
		high=a[n-1]-a[0];
		while(low<=high)
		{
			mid=(low+high)/2;
			cows=c;
			prevPos=0;
			for(k=1;k<n;k++)
			{
				if((a[k]-a[prevPos])>=mid && (cows>1))
				{
					prevPos=k;
					cows--;
				}
			}
			if(cows==1)
			{
				low=mid+1;
				best=mid;
			}
			else
			{
				high=mid-1;
			}
		}
	cout<<best<<endl;
	}
 
	return 0;
}