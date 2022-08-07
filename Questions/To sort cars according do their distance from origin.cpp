// To sort cars according do their distance from origin

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

// Applying distance formula to find distance b/w car & origin
// Sorting in ascending order of distance
int compare(pair<int,int> a,pair<int,int> b)
{
    return sqrt((a.first*a.first)+(a.second*a.second)) <= sqrt((b.first*b.first)+(b.second*b.second));
}

int main()
{
    int n,i,x,y,z;
    cin>>n;
    vector< pair<int,int> > a;
    vector<int> b;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end(),compare);
    for(i=0;i<n;i++)
    cout<<a[i].first<<","<<a[i].second<<endl;
    return 0;
}