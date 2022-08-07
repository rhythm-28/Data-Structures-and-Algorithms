// Given n Cartesian points, find the number of axes parallel rectangles 

#include<iostream>
#include<utility>
#include<set>
using namespace std;

int rectangle_counting(set<pair<int,int>> s)
{
    int count=0;
    for(auto i=s.begin();i!=s.end();i++)
    {
        for(auto j=next(i);j!=s.end();j++)
        {
            pair<int,int> p1=*i;
            pair<int,int> p3=*j;
            if(p1.first!=p3.first && p1.second!=p3.second)
            {
                pair<int,int> p2;
                pair<int,int> p4;
                p2.first=p3.first;
                p2.second=p1.second;
                p4.first=p1.first;
                p4.second=p3.second;

                if(s.find(p2)!=s.end() && s.find(p4)!=s.end())
                count++;
            }
        }
    }
    return count/2;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    set<pair<int,int>> s;
    int i,n,x,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        s.insert(make_pair(x,y));
    }   
    cout<<rectangle_counting(s);
    return 0;
}