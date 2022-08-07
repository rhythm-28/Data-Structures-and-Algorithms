// Expedition (SPOJ)

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
}

int main()    
{
    int t,x,y,n,i,distance,fuel,prev,current_distance,count,flag;
    vector<pair<int,int>> v;
    priority_queue<int> p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }   
        cin>>distance>>fuel;
        
        for(i=0;i<n;i++)
        v[i].first=distance-v[i].first;

        sort(v.begin(),v.end(),compare);

        prev=0,i=0,count=0,flag=0;

        while(i<n)
        {
            current_distance=v[i].first-prev;
            if(fuel>=current_distance)
            {
                fuel-=current_distance;
                prev=v[i].first;
                p.push(v[i].second);
            }
            else
            {
                if(p.empty())
                {
                    flag=-1;
                    break;
                }

                else
                {
                    fuel+=p.top();
                    p.pop();
                    count++;
                    continue;
                }
            }
            i++;
        }

        if(flag==-1)
        cout<<-1;
        
        else
        {
            flag=0;
            current_distance=distance-v[n-1].first;
            if(fuel>=current_distance)
            cout<<count;

            else
            {
                while(fuel<current_distance)
                {
                    if(p.empty())
                    {
                        flag=-1;
                        break;
                    }

                    else
                    {
                        fuel+=p.top();
                        p.pop();
                        count++;
                    }
                }
                if(flag==-1)
                cout<<-1;
                else
                cout<<count;
            }
        }
        cout<<endl;
        v.clear();
        while(!p.empty())
        {
            p.pop();
        }
    }
    return 0;
}