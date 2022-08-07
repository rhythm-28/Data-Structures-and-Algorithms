// Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int v, vector<vector<int>> g[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(v, false);

    int ans = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int cur = top.second, bestWeight = top.first;
        if (!visited[cur])
        {
            ans += bestWeight;
            visited[cur] = true;
            for (auto v : g[cur])
            {
                int nbr = v[0], edgeWeight = v[1];
                if (!visited[nbr])
                    pq.push({edgeWeight, nbr});
            }
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}