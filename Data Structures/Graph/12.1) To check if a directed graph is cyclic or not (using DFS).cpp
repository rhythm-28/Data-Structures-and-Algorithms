// To check if a directed graph is cyclic or not (using DFS)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> m;

public:
    void add_edge(int x, int y)
    {
        m[x].push_back(y);
    }

    bool dfs(int cur, vector<bool> &visited, vector<bool> &isInPath)
    {
        visited[cur] = true;
        isInPath[cur] = true;
        for (auto nbr : m[cur])
        {
            if (visited[nbr] == true)
            {
                if (isInPath[nbr] == true)
                    return true;
            }
            else
            {
                if (dfs(nbr, visited, isInPath))
                    return true;
            }
        }
        isInPath[cur] = false;
        return false;
    }

    bool is_cyclic(int v)
    {
        vector<bool> visited(v, false), isInPath(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, isInPath))
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