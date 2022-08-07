#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, vector<pair<int, int>>> m;
    void addEdge(int x, int y, int weight)
    {
        m[x].push_back({y, weight});
        m[y].push_back({x, weight});
    }
    void Dijkstra(int v, int src)
    {
        set<pair<int, int>> s;
        vector<int> distance(v, INT_MAX);
        vector<int> parent(v, -1);

        distance[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {
            pair<int, int> curNode = *(s.begin());
            int curDistance = curNode.first, cur = curNode.second;
            s.erase(s.begin());

            for (auto edge : m[cur])
            {
                int nbr = edge.first, edgeWeight = edge.second;
                int oldWeight = distance[nbr];
                int newWeight = curDistance + edgeWeight;

                if (newWeight < oldWeight)
                {
                    pair<int, int> oldPair = {oldWeight, nbr};
                    if (s.find(oldPair) != s.end())
                        s.erase(oldPair);

                    s.insert({newWeight, nbr});
                    distance[nbr] = newWeight;
                    parent[nbr] = cur;
                }
            }
        }
        for (int i = 0; i < v; i++)
            cout << i << " -> " << distance[i] << endl;
        cout << endl;
        int dest;
        for (int i = 0; i < v; i++)
        {
            dest = i;
            while (dest != -1)
            {
                cout << dest << " <- ";
                dest = parent[dest];
            }
            dest = i;
            cout << endl;
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v, e, i, x, y, weight, src;
    Graph g;
    cin >> v >> e;
    for (i = 0; i < e; i++)
    {
        cin >> x >> y >> weight;
        g.addEdge(x, y, weight);
    }
    cin >> src;
    g.Dijkstra(v, src);
    return 0;
}

/*
Input:
9 14
0 1 4
0 2 8
1 2 11
1 3 8
2 4 7
2 5 1
3 4 2
4 5 6
3 6 7
5 7 2
3 7 4
6 7 14
6 8 9
7 8 10
0

Output:
0 -> 0
1 -> 4
2 -> 8
3 -> 12
4 -> 14
5 -> 9
6 -> 19
7 -> 11
8 -> 21
*/