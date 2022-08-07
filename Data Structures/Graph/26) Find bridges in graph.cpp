// Find bridges in graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &g, int &count, vector<int> &a, vector<int> &b, vector<vector<int>> &c, int parent)
{
    a[cur] = b[cur] = count;
    count++;
    for (int nbr : g[cur])
    {
        if (nbr == parent)
            continue;

        // not visited
        if (a[nbr] == -1)
        {
            dfs(nbr, g, count, a, b, c, cur);

            if (b[nbr] > a[cur])
                c.push_back({cur,
                             nbr});
        }

        b[cur] = min(b[cur], b[nbr]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, e, x, y;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> a(v, -1), b(v, -1);
    int count = 1;
    vector<vector<int>> c;
    dfs(0, g, count, a, b, c, -1);
    for (auto v : c)
        cout << v[0] << " " << v[1] << endl;
    return 0;
}