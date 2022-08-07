// To check if a directed graph is cyclic or not (using BFS)
// Kahn's Algorithm
// TC:O(V+E) 

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> m;

public:
    void add_edge(int x, int y)
    {
        m[x].push_back(y);
    }

    bool isCyclic(int v)
    {
        vector<int> indegree(v, 0);
        queue<int> q;
        int i, cur, count = 0;
        for (i = 0; i < v; i++)
        {
            for (int x : m[i])
                indegree[x]++;
        }
        for (i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            count++;
            for (int nbr : m[cur])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        if (count != v)
            return true;
        else
            return false;
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
    bool ans = g.isCyclic(v);
    if (ans == true)
        cout << "cycle exists";
    else
        cout << "cycle does not exist";
    return 0;
}