#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, vector<int>> m;
    void insert(int x, int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void input()
    {
        int i, v, e, x, y;
        cin >> v >> e;
        for (i = 0; i < e; i++)
        {
            cin >> x >> y;
            insert(x, y);
        }
    }
    void dfs(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto nbr : m[src])
        {
            if (!visited[nbr])
                dfs(nbr, visited);
        }
    }
    void solve()
    {
        input();
        map<int, bool> visited;
        for (auto p : m)
            visited[p.first] = false;
        for (auto p : m)
        {
            if (!visited[p.first])
            {
                dfs(p.first, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    graph g;
    g.solve();
    return 0;
}