// Implementation of an undirected graph with integers as vertices

#include<iostream>
#include<list>
using namespace std;

class Graph
{
    // v=no of vertices
    int v;
    list<int> *l;
    public:
    Graph(int vertices)
    {
        v=vertices;
        l=new list<int>[v];
    }
    void add_edge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" -> ";
            for(auto a:l[i])
            cout<<a<<",";
            cout<<endl;
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,i,x,y;
    cin>>v;
    Graph g(v);
    for(i=0;i<v;i++)
    {
        cin>>x>>y;
        g.add_edge(x,y);
    }
    g.print();

    return 0;
}