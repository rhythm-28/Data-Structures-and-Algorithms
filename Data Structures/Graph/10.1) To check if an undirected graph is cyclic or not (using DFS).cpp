// To check if an undirected graph is cyclic or not (using DFS)

#include<bits/stdc++.h>
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

    bool dfs(int cur, vector<bool> &visited, int parent)
    {
        visited[cur] = true;
        for (auto nbr : m[cur])
        {
            if (visited[nbr] == true)
            {
                if (parent != nbr)
                    return true;
            }
            else
            {
                if (dfs(nbr, visited, cur))
                    return true;
            }
        }
        return false;
    }

    bool is_cyclic(int v)
    {
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, -1))
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