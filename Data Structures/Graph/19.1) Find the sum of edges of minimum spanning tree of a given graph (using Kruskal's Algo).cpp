// Find the sum of edges of minimum spanning tree of a given graph
// Kruskal's Algorithm

#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class DSU
{
    map<int,int> parent;
    map<int,int> rank;

    public:

    void initialize(vector<vector<int>> edges)
    {
        for(auto edge: edges)
        {
            parent[edge[1]]=-1;
            parent[edge[2]]=-1;
            rank[edge[1]]=1;
            rank[edge[2]]=1;
        }
    }
    
    int find_leader(int x)
    {   
        if(parent[x]==-1)
        return x;

        else
        return parent[x]=find_leader(parent[x]);
    }

    void unite(int x,int y)
    {
        int leader1=find_leader(x);
        int leader2=find_leader(y);

        // union possible
        // so doing union
        if(leader1!=leader2)
        {
            if(rank[leader1]>rank[leader2])
            {
                parent[leader2]=leader1;
                rank[leader1]+=rank[leader2];
            }
            else
            {
                parent[leader1]=leader2;
                rank[leader2]+=rank[leader1];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edges;
    DSU s;
    public:

    void add_edge(int weight,int x,int y)
    {
        edges.push_back({weight,x,y});
    }

    int MST()
    {
        s.initialize(edges);
        int ans=0;
        sort(edges.begin(),edges.end());
        for(auto edge:edges)
        {
            int w=edge[0];
            int a=edge[1];
            int b=edge[2];

            if(s.find_leader(a)!=s.find_leader(b))
            {
                s.unite(a,b);
                ans+=w;
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

    Graph g;
    int i,e,x,y,w,n;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        g.add_edge(w,x,y);
    }
    cout<<g.MST();
    return 0;
}