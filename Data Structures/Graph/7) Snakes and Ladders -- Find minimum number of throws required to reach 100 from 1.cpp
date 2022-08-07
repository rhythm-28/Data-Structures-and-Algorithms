// Snakes and Ladders
// The player has total control over outcome of dice throw
// Find minimum number of throws required to reach 100 from 1
// Also print the path

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
    }
    void bfs_print(T src,T dest)
    {
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;

        for(auto p: m)
        distance[p.first]=INT_MAX;

        q.push(src);
        distance[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto nbr: m[node])
            {
                if(distance[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr]=distance[node]+1;
                    parent[nbr]=node;
                }
            }
        }

        for(auto p: m)
        {
            if(p.first==dest)
            cout<<distance[p.first]<<endl;
        }

        T temp=dest;
        while(temp!=src)
        {
            cout<<temp<<"<-";
            temp=parent[temp];
        }
        cout<<temp;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t,n,m,i,j,dice,x,y,board[101];
    cin>>t;
    while(t--)
    {
        for(i=0;i<=100;i++)
        board[i]=0;
        Graph<int> g;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            board[x]=y-x;
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            board[x]=y-x;
        }
        for(i=1;i<100;i++)
        {
            for(dice=1;dice<=6;dice++)
            {
                j=i+dice;
                j+=board[j];
                if(j<=100)
                g.add_edge(i,j);
            }
        }
        g.add_edge(100,100);
        g.bfs_print(1,100);
        cout<<endl;
    }

    return 0;
}