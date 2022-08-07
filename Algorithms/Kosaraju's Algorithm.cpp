// To find strongly connected components in directed graph
// Kosaraju's Algorithm

#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T>> m;
    public:
    void add_edge(T x,T y)
    {
        m[x].push_back(y);
    }

    void dfs(T src,map<T,bool> &visited,vector<int> &a)
    {
        visited[src]=true;
        for(auto nbr: m[src])
        {
            if(!visited[nbr])
            dfs(nbr,visited,a);
        }
        a.push_back(src);
    }

    void dfs_call(vector<int> &a)
    {
        map<T,bool> visited;

        for(auto p:m)
        visited[p.first]=false;
        
        for(auto p:m)
        {
            if(!visited[p.first])
            dfs(p.first,visited,a);
        }
    }
};

template<typename T>
class rev_Graph
{
    map<T,list<T>> m;
    public:
    void add_edge(T x,T y)
    {
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

    void dfs_print(vector<int> a)
    {
        map<T,bool> visited;
        for(auto p:m)
        visited[p.first]=false;
        int count=0;
        for(auto it=a.begin();it!=a.end();it++)
        {
            if(!visited[*it])
            {
                cout<<"scc "<<count<<" -> ";
                dfs(*it,visited);
                cout<<endl;
                count++;
            }
        }
    }
};

void solve(Graph<int> g,rev_Graph<int> g2)
{
    // step-1
    // dfs to get ordering
    vector<int> a;
    g.dfs_call(a);
    // step-2
    // reverse graph
    // reverse graph already created

    // step-3 
    // reverse vector
    reverse(a.begin(),a.end());

    // step-3
    // dfs using reversed vector
    g2.dfs_print(a);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,i,e;
    int x,y;
    Graph<int> g;
    rev_Graph<int> g2;

    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
        g2.add_edge(x,y);
    }
    solve(g,g2);
    return 0;
}