// Find the minimum fare required to go from src to dest
// train, flight fare is given
// Atmost 1 flight can be taken

#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

template<typename T>
class Graph
{
    // current, neighbours => list of (neighbour name,train fare, flight fare)
    map<T,list<pair<string,pair<int,int>>>> m;
    public:
    void add_edge(T x,T y,int train, int flight,bool bidir)
    {
        m[x].push_back(make_pair(y,make_pair(train,flight)));
        
        if(bidir)
        m[y].push_back(make_pair(x,make_pair(train,flight)));
    }

    unordered_map<string,int> Dijkstra(T src)
    {
        unordered_map<string,int> distance;
        set<pair<int,string>> s;
        unordered_map<T,T> parent_map;

        // Initialization
        for(auto p:m)
        distance[p.first]=INT_MAX;
        distance[src]=0;

        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto node=*(s.begin());
            T parent=node.second;
            int parent_weight=node.first;
            s.erase(s.begin());

            // Traverse over all its neighbours
            for(auto p:m[parent])
            {
                int edge_weight=p.second.first;
                int old_weight=distance[p.first];
                int new_weight=parent_weight+edge_weight;

                // update distance and set
                if(new_weight<old_weight)
                {
                    pair<int,string> x=make_pair(old_weight,p.first);

                    // if it exists in set, delete it
                    if(s.find(x)!=s.end())
                    s.erase(x);

                    // add it to set and distance map
                    distance[p.first]=new_weight;
                    s.insert(make_pair(distance[p.first],p.first));
                    parent_map[p.first]=node.second;
                }
            }
        }
        return distance;
    }

    int minimum_fare(T src,T dest)
    {
        // 0 flight case

        int a;
        unordered_map<string,int> dist1 = Dijkstra(src);
        for(auto p:dist1)
        {
            if(p.first==dest)
            a=p.second;
        }

        // 1 flight case

        // step-1
        // find distance b/w src to all nodes => dist1 (already calculated above)
        // find distance b/w dest to all nodes => dist2 
        unordered_map<string,int> dist2 = Dijkstra(dest);

        // step-2
        T x,y;
        int train_till_x,flight_x_to_y,train_till_dest;
        int final_fare=INT_MAX, cur_fare;
        for(auto p:m)
        {
            x=p.first;
            for(auto q:p.second)
            {
                y=q.first;
                train_till_x=dist1[x];
                flight_x_to_y=q.second.second;
                train_till_dest=dist2[y];
                cur_fare=train_till_x+flight_x_to_y+train_till_dest;
                final_fare=min(cur_fare,final_fare);
            }
        }
        return min(a,final_fare);
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e,i,train,flight;
    string x,y,src,dest;
    bool bidir;
    Graph<string> g;
    cin>>e;
    for(i=0;i<e;i++)
    {   
        cin>>x>>y>>train>>flight>>bidir;
        g.add_edge(x,y,train,flight,bidir);
    }
    cin>>src>>dest;
    cout<<g.minimum_fare(src,dest);
    return 0;
}