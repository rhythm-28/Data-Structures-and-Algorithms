// To find components of a undirected graph 

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

    void dfs(T src,map<T,bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        for(auto nbr: m[src])
        {
            if(!visited[nbr])
            dfs(nbr,visited);
        }
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
                cout<<count<<"->";
                dfs(p.first,visited);
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