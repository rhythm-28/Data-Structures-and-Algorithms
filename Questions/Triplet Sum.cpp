// Triplet Sum
//  O(n^2)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int i,j,k,n,sum,y,z;
    vector<int> a;
    cin>>n;
    for(i=0;i<n;i++)
	{
		cin>>y;
		a.push_back(y);
	}
    sort(a.begin(),a.end());
    cin>>sum;
    i=0;
    while(i<n)
    {
        j=i+1,k=n-1;
        z=sum-a[i];
        while(j<k)
        {
            if((a[j]+a[k])==z)
            {
                cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
                j++;
            }
            else if((a[j]+a[k])<z)
            j++;
            else
            k--;
        }
        i++;
    }
    return 0;
}
