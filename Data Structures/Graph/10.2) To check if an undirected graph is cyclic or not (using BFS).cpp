// To check if an undirected graph is cyclic or not (using BFS)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> m;

public:
    void add_edge(int x, int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    bool bfs(int src, vector<bool> &visited, vector<int> &parent)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nbr : m[cur])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = cur;
                }
                else
                {
                    if (nbr != parent[cur])
                        return true;
                }
            }
        }
        return false;
    }

    bool is_cyclic(int v)
    {
        vector<bool> visited(v, false);
        vector<int> parent(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (bfs(i, visited, parent))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int e, i;
    int x, y, v, src;
    cin >> v >> e;
    Graph g;
    for (i = 0; i < e; i++)
    {
        cin >> x >> y;
        g.add_edge(x, y);
    }
    bool ans = g.is_cyclic(v);
    if (ans == true)
        cout << "cycle exists";
    else
        cout << "cycle does not exist";
    return 0;
}