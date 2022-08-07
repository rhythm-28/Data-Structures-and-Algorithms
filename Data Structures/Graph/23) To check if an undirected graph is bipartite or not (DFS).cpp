// To check if an undirected graph is bipartite or not (DFS)

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> m;

public:
    void add_edge(T x, T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    bool dfs(int cur, vector<int> &visited, int color)
    {
        visited[cur] = color;
        for (int nbr : m[cur])
        {
            if (visited[nbr] == 0)
            {
                if (!dfs(nbr, visited, 3 - color))
                    return false;
            }
            else
            {
                if (visited[nbr] == color)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(int n)
    {
        int i;
        vector<int> visited(n, 0);
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i,visited, 1))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, i, e;
    int x, y, dest;
    cin >> v >> e;
    Graph<int> g;
    cin >> x >> y;
    g.add_edge(x, y);
    for (i = 1; i < e; i++)
    {
        cin >> x >> y;
        g.add_edge(x, y);
    }
    bool ans = g.isBipartite(v);
    if (ans)
        cout << "bipartite graph";
    else
        cout << "not a bipartite graph";
    return 0;
}