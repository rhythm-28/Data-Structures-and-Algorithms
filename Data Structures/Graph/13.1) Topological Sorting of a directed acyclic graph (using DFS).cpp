// Topological Sorting of a directed acyclic graph (using DFS)

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> m;

public:
    void add_edge(T x, T y)
    {
        m[x].push_back(y);
    }

    void dfs(T src, map<T, bool> &visited, vector<int> &ordering)
    {
        visited[src] = true;
        for (auto nbr : m[src])
        {
            if (!visited[nbr])
                dfs(nbr, visited, ordering);
        }
        ordering.push_back(src);
    }

    void dfs_print()
    {
        map<T, bool> visited;
        vector<int> ordering;
        for (auto p : m)
            visited[p.first] = false;

        for (auto p : m)
        {
            if (!visited[p.first])
                dfs(p.first, visited, ordering);
        }

        reverse(ordering.begin(), ordering.end());

        for (auto e : ordering)
            cout << e << " ";
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, i;
    int x, y, src, dest;
    cin >> v;
    Graph<int> g;
    for (i = 0; i < v; i++)
    {
        cin >> x >> y;
        g.add_edge(x, y);
    }
    g.dfs_print();

    return 0;
}