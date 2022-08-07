// Find the shortest distance from source to each node of a weighed directed graph (+ve & -ve weights)
// Bellman-Ford Algorithm
// O(V*E)

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

void Bellman_Ford(vector<vector<int>> edges,int src,int v)
{
    // Step-1 
    // Initialization
    unordered_map<int,int> distance;
    for(auto edge:edges)
    {
        int x=edge[0];
        int y=edge[1];
        distance[x]=INT_MAX;
        distance[y]=INT_MAX;
    }
    distance[src]=0;

    // Step-2 
    // Relax all edges v-1 times
    for(int i=1;i<=v-1;i++)
    {
        for(auto edge:edges)
        {
            int x=edge[0];
            int y=edge[1];
            int weight=edge[2];

            if(distance[x]!=INT_MAX)
            {
                if(distance[x]+weight < distance[y])
                distance[y]=distance[x]+weight;
            }
        }
    }

    // Step-3
    // Check for negative weight cycle
    // if values change in vth iteration, then it exists
    for(auto edge:edges)
    {
        int x=edge[0];
        int y=edge[1];
        int weight=edge[2];

        if(distance[x]!=INT_MAX)
        {
            if(distance[x]+weight < distance[y])
            {
                cout<<"negative weight cycle exists";
                return;
            }
        }
    }

    for(auto p:distance)
    cout<<p.first<<" -> "<<p.second<<endl;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int x,y;
    int i,w,v,src,e;
    vector<vector<int>> edges;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        edges.push_back({x,y,w});
    }
    cin>>src;
    Bellman_Ford(edges,src,v);
    return 0;
}