// To check if an undirected graph is a tree or not (using DFS)

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

    bool isCyclic(int cur, vector<bool> &visited, int parent)
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
                if (isCyclic(nbr, visited, cur))
                    return true;
            }
        }
        return false;
    }

    bool is_Tree(int v)
    {
        vector<bool> visited(v, false);

        // is cyclic
        if (isCyclic(0, visited, -1))
            return false;

        for (int i = 0; i < v; i++)
        {
            // not connected
            if (!visited[i])
                return false;
        }

        // connected and not cyclic
        return true;
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
    bool ans = g.is_Tree(v);
    if (ans == true)
        cout << "given graph is a tree";
    else
        cout << "not a tree";
    return 0;
}