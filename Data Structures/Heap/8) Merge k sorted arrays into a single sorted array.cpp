// Merge k sorted arrays into a single sorted array
// O[ n*k*log(k) ]

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,pair<int,int>> PAIR;

vector<int> merge(vector<vector<int>> a)
{
    priority_queue<PAIR,vector<PAIR>,greater<PAIR>> h;

    vector<int> ans;

    int i,k=a.size();
    for(i=0;i<k;i++)
    {
        PAIR b;
        b.first=a[i][0];
        b.second.first=i;
        b.second.second=0;
        h.push(b);
    }
    while(!h.empty())
    {
        PAIR c=h.top();
        h.pop();

        int element=c.first;
        int x=c.second.first;
        int y=c.second.second;

        ans.push_back(element);

        if(y+1<a[x].size())
        {
            PAIR d;
            d.first=a[x][y+1];
            d.second.first=x;
            d.second.second=y+1;
            h.push(d);
        }
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>> a;
    vector<int> temp;
    int i,j,n,k,d;
    cin>>n;
    cin>>k;
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>d;
            temp.push_back(d);
        }
        a.push_back(temp);
        temp.clear();
    }
    vector<int> ans;
    ans=merge(a);
    for(auto x:ans)
    cout<<x<<" ";

    return 0;
}