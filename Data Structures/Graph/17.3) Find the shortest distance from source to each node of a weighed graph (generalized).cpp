// Find the shortest distance from source to each node of a weighed graph
// Dijkstra's Algorithm

#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<map>
#include<unordered_map>
#include<set>
#include<utility>
#include<climits>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<pair<T,int>>> m;
    public:
    void add_edge(T x,T y,int weight,bool bidir)
    {
        m[x].push_back(make_pair(y,weight));
        
        if(bidir)
        m[y].push_back(make_pair(x,weight));
    }

    void Dijkstra(T src)
    {
        unordered_map<string,int> distance;
        set<pair<int,string>> s;

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
                int edge_weight=p.second;
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
                    
                }
            }
        }

        for(auto p:distance)
        cout<<src<<" to "<<p.first<<" -> "<<p.second<<endl;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e,i,weight;
    string x,y,src;
    bool bidir;
    Graph<string> g;
    cin>>e;
    for(i=0;i<e;i++)
    {   
        cin>>x>>y>>weight>>bidir;
        g.add_edge(x,y,weight,bidir);
    }
    cin>>src;
    g.Dijkstra(src);


    /* 
    Input:
    14
    Delhi Bombay 4 1
    Delhi Kanpur 8 1
    Bombay Kanpur 11 1
    Bombay Lucknow 8 1
    Kanpur Kerala 7 1
    Kanpur Srinagar 1 1
    Lucknow Kerala 2 1
    Kerala Srinagar 6 1
    Lucknow Nanital 7 1
    Srinagar Arunachal 2 1
    Lucknow Arunachal 4 1
    Nanital Arunachal 14 1
    Nanital NYC 9 1
    Arunachal NYC 10 1
    Delhi
    */
    return 0;
}