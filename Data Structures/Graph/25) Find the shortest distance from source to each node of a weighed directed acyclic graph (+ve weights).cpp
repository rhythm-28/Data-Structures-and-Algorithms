// Find the shortest distance from source to each node of a weighed directed acyclic graph (+ve weights)
// TC: O(V+E)
// SC: O(V)

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int cur, vector<vector<pair<int, int>>> &g, vector<bool> &visited, vector<int> &a)
{
    visited[cur] = true;
    for (auto p : g[cur])
    {
        int nbr = p.first;
        if (!visited[nbr])
            topologicalSort(nbr, g, visited, a);
    }
    a.push_back(cur);
}

vector<int> solve(vector<vector<pair<int, int>>> &g, int src, int v)
{
    vector<bool> visited(v,false);
    vector<int> a;
    int i, cur;
    for (i = 0; i < v; i++)
    {
        if (!visited[i])
            topologicalSort(i, g, visited, a);
    }
    reverse(a.begin(), a.end());
    
    vector<int> distance(v, INT_MAX);
    distance[src]=0;
    for (i = 0; i < v; i++)
    {
        cur = a[i];
        if (distance[cur] != INT_MAX)
        {
            for (auto p : g[cur])
            {
                int nbr = p.first, edgeWeight = p.second;
                if (distance[cur] + edgeWeight < distance[nbr])
                    distance[nbr] = distance[cur] + edgeWeight;
            }
        }
    }

    return distance;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    int i, w, v, src, e;
    cin >> v >> e >> src;
    vector<vector<pair<int, int>>> g(v);
    for (i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        g[x].push_back({y, w});
    }
    vector<int> distance = solve(g, src, v);
    for (int x : distance)
        cout << x << " ";
    return 0;
}