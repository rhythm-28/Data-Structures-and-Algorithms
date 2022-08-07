// Find articulation points in graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &g, vector<int> &a, vector<int> &b, set<int> &c, int timer, int parent)
{
    a[cur] = b[cur] = timer;
    timer++;
    int individualChild = 0;
    for (int nbr : g[cur])
    {
        if (nbr == parent)
            continue;

        // not visited
        if (a[nbr] == -1)
        {
            dfs(nbr, g, a, b, c, timer, cur);

            // update shortest time
            b[cur] = min(b[cur], b[nbr]);

            // articulation point condition
            if (b[nbr] >= a[cur] && parent != -1)
                c.insert(cur);

            individualChild++;
        }

        // update shortest time
        else
            b[cur] = min(b[cur], a[nbr]);
    }

    // for starting node
    if (parent == -1)
    {
        if (individualChild > 1)
            c.insert(cur);
    }
}

vector<int> articulationPoints(int v, vector<vector<int>> &g)
{
    set<int> c;
    vector<int> a(v, -1), b(v, -1), ans;
    int i, timer = 1;
    for (i = 0; i < v; i++)
    {
        if (a[i] == -1)
            dfs(i, g, a, b, c, timer, -1);
    }
    for (auto x : c)
        ans.push_back(x);
    if (ans.size() == 0)
        ans.push_back(-1);
    return ans;
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
    vector<int> c = articulationPoints(v, g);
    for (auto x : c)
        cout << x << " ";
    return 0;
}