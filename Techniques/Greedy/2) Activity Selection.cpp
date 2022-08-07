//Activity Selection 

#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

int main()
{
    int t,n,i,count,temp;
    pair<int,int> p[10000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
        sort(p,p+n,compare);
        count=1;
		temp=p[0].second;
        for(i=1;i<n;i++)
        {
            if(p[i].first>=temp)
			{
				count++;
				temp=p[i].second;
			}
        }
        cout<<count<<endl;
    }
    return 0;
}