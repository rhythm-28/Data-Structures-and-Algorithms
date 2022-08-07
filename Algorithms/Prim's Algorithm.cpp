// Find the sum of edges of minimum spanning tree of a given graph
// Prim's Algorithm

#include<iostream>
#include<list>
#include<map>
#include<utility>
#include<queue>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<pair<int,T>>> m;
    public:
    void add_edge(T x,T y,int weight)
    {
        m[x].push_back(make_pair(weight,y));
        m[y].push_back(make_pair(weight,x));
    }

    int Prism(T src)
    {
        priority_queue< pair<int,T>,vector<pair<int,T>>,greater<pair<int,T>>> pq;
        map<T,bool> visited;
        int ans=0;
        pq.push(make_pair(0,src));
        while(!pq.empty())
        {
            auto best=pq.top();
            pq.pop();
            int weight=best.first;
            T node=best.second;

            // check if vertex is already in MST set
            if(!visited[node])
            {
                ans+=weight;
                visited[node]=1;
                for(auto nbr:m[node])
                {
                    if(!visited[nbr.second])
                    pq.push(make_pair(nbr.first,nbr.second));
                }
            }
        }
        return ans;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e,i,weight,m,x,y,src;
    Graph<int> g;

    cin>>m>>e;

    cin>>x>>y>>weight;
    src=x;
    g.add_edge(x,y,weight);
    for(i=1;i<e;i++)
    {   
        cin>>x>>y>>weight;
        g.add_edge(x,y,weight);
    }
    cout<<g.Prism(src);
    return 0;
}