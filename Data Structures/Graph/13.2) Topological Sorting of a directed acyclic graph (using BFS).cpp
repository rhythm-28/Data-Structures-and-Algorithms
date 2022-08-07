// Topological Sorting of a directed acyclic graph (using BFS)
// Kahn's Algorithm
// TC:O(V+E) 

#include<iostream>
#include<map>
#include<list>
#include<queue>
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
    void bfs_print(int vertices)
    {
        int indegree[1000],i;
        for(i=0;i<vertices;i++)
        indegree[i]=0;
        
        // finding indegree
        for(auto p:m)
        {
            for(auto e:p.second)
            indegree[e]++;
        }

        // pushing those with 0 indegree
        queue<int> q;
        for(i=0;i<vertices;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr: m[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
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

    int v,i,e,x,y,vertices;
    Graph<int> g;
    cin>>vertices;
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    g.bfs_print(vertices);

    return 0;
}