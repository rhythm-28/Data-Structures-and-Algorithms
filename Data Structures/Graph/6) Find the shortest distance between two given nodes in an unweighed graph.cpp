// Single source shortest path
// To find distance between 2 given nodes of an unweighed graph

#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T>> m;
    public:
    void add_edge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void bfs_print(T src,T dest)
    {
        queue<T> q;
        map<T,int> distance;

        for(auto p: m)
        distance[p.first]=INT_MAX;

        q.push(src);
        distance[src]=0;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto nbr: m[node])
            {
                if(distance[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr]=distance[node]+1;
                }
            }
        }
           cout<<distance[p.first]<<endl;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,i;
    int x,y,src,dest;
    cin>>v;
    Graph<int> g;
    for(i=0;i<v;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    cin>>src>>dest;
    g.bfs_print(src,dest);

    return 0;
}