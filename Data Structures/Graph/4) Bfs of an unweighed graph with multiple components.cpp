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

    void bfs(int src, map<int, bool> &visited)
    {
        queue<int> q;
        int level = 0;
        visited[src] = true;
        q.push(src);
        level++;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int cur = q.front();
                cout << cur << " ";
                q.pop();
                for (auto nbr : m[cur])
                {
                    if (!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            cout << endl;
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
                bfs(p.first, visited);
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