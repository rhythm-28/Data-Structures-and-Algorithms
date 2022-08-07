// To check if a cycle exists in an undirected graph or not (optimized)
// both Path compression and Union by rank
// ~ O(1)

#include<iostream>
#include<list>
#include<utility>
#include<string>
#include<map>
using namespace std;

template<typename T>
class Graph
{
    list<pair<T,T>> edges;
    public:
    void add_edge(T x,T y)
    {
        edges.push_back(make_pair(x,y));
    }

    T find_leader(T x,map<T,T> parent)
    {   
        if(parent[x]==-1)
        return x;

        else
        return parent[x]=find_leader(parent[x],parent);
    }

    bool cycle_exists(int e)
    {
        map<T,T> parent;
        map<T,int> rank;
       
        // if T=int
        for(auto edge: edges)
        {
            parent[edge.first]=-1;
            parent[edge.second]=-1;
            rank[edge.first]=1;
            rank[edge.second]=1;
        }

        for(auto edge:edges)
        {
            T x=edge.first,y=edge.second;
            T leader1=find_leader(x,parent);
            T leader2=find_leader(y,parent);

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

            else
            return true;
        }
        return false;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e,i;
    int x,y;
    cin>>e;
    Graph<int> g;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    bool ans=g.cycle_exists(e);
    if(ans)
    cout<<"cycle exists";
    else
    cout<<"cycle does not exist";
    return 0;
}