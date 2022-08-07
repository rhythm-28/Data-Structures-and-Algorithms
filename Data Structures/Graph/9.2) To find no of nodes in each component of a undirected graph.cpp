// To find no of nodes in each component of a undirected graph 

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

    int dfs(T src,map<T,bool> &visited,int count_nodes)
    {
        visited[src]=true;
        for(auto nbr: m[src])
        {
            if(!visited[nbr])
            count_nodes=dfs(nbr,visited,count_nodes+1);
        }
        return count_nodes;
    }

    void dfs_print()
    {
        map<T,bool> visited;
        for(auto p:m)
        visited[p.first]=false;
        
        int count=0;
        for(auto p:m)
        {
            if(!visited[p.first])
            {
                cout<<count<<" -> ";
                int count_nodes=1;
                cout<<dfs(p.first,visited,count_nodes);
                cout<<endl;
                count++;
            }
        }
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
    g.dfs_print();

    return 0;
}