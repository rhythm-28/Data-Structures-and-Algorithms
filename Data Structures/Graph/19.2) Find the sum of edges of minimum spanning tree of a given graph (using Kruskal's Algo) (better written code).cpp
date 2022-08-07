#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] == -1)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    bool Union(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);

        if (s1 != s2)
        {
            if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            return false;
        }
        else
            return true;
    }

    int spanningTree(int v, vector<vector<int>> g[])
    {
        vector<int> parent(v, -1), rank(v, 1);
        int i, ans = 0;
        vector<vector<int>> s;
        for (i = 0; i < v; i++)
        {
            for (auto a : g[i])
                s.push_back({a[1], i, a[0]});
        }
        sort(s.begin(), s.end());
        for (auto cur : s)
        {
            int weight = cur[0], x = cur[1], y = cur[2];
            if (!Union(x, y, parent, rank))
                ans += weight;
        }
        return ans;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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

    Solution obj;
    cout << obj.spanningTree(V, adj);

    return 0;
}