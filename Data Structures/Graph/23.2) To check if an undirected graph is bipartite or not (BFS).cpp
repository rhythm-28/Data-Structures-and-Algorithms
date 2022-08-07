// To check if an undirected graph is bipartite or not (BFS)

#include <bits/stdc++.h>
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

    bool bfs(int cur, int color, vector<int> &visited)
    {
        queue<int> q;
        q.push(cur);
        visited[cur] = color;
        while (!q.empty())
        {
            int cur = q.front();
            color = visited[cur];
            q.pop();
            for (int nbr : g[cur])
            {
                if (visited[nbr] == 0)
                {
                    q.push(nbr);
                    visited[nbr] = 3 - color;
                }
                else
                {
                    if (color == visited[nbr])
                        return false;
                }
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
                if (!bfs(i, 1, visited))
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