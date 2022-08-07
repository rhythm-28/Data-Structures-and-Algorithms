// Weighted graph with strings as vertices

#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>
#include<list>
using namespace std;

class Graph
{
    unordered_map<string,list<pair<string,int>>> um;
    public:
    void add_edge(string a,string b,int x,bool bidir)
    {
        um[a].push_back(make_pair(b,x));

        if(bidir==true)
        um[b].push_back(make_pair(a,x));
    }
    void print()
    {
        for(auto p:um)
        {
            cout<<p.first<<" -> ";
            for(auto q : p.second)
            cout<<q.first<<"-"<<q.second<<",";
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
    
    Graph g;
    string a,b;
    int x;
    bool bidir;

    int i,e;
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b>>x>>bidir;
        g.add_edge(a,b,x,bidir);
    }
    g.print();
    return 0;
}