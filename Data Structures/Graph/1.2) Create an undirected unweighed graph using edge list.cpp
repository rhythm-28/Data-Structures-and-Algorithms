// Create an undirected unweighed graph using edge list

#include<iostream>
#include<list>
#include<utility>
#include<string>
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

    void print()
    {
        for(auto edge:edges)
        cout<<"("<<edge.first<<","<<edge.second<<")"<<endl;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int e,i;
    string x,y;
    cin>>e;
    Graph<string> g;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    g.print();
    return 0;
}