#include <bits/stdc++.h>
using namespace std;

void ordering(int cur, vector<int> g[], vector<int> &a, vector<bool> &visited)
{
    visited[cur] = true;
    for (int nbr : g[cur])
    {
        if (!visited[nbr])
            ordering(nbr, g, a, visited);
    }
    a.push_back(cur);
}

int kosaraju(int v, vector<int> g[])
{
    // step 1-> find ordering
    int i;
    vector<int> a;
    vector<bool> visited(v, false);
    for (i = 0; i < v; i++)
    {
        if (!visited[i])
            ordering(i, g, a, visited);
    }
    reverse(a.begin(), a.end());

    // step 2-> reverse graph
    vector<int> g2[v];
    for (i = 0; i < v; i++)
    {
        for (int x : g[i])
            g2[x].push_back(i);
    }

    // step 3-> dfs to find no of components
    vector<bool> visited2(v, false);
    int count = 0;
    for (i = 0; i < v; i++)
    {
        if (!visited2[a[i]])
        {
            count++;
            ordering(a[i], g2, a, visited2);
        }
    }
    return count;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout<<kosaraju(V, adj);
    }

    return 0;
}