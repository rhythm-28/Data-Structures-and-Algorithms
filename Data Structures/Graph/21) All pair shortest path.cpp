// All pair shortest path
// Floyd Warhsall Algorithm
// O(V^3)
// V => no of vertices

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF 1000

void Floyd_Warshall(int v, int dp[100][100])
{
    int i, j, k;
    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (i != k && j != k & i != j)
                {
                    if (dp[i][k] != INF && dp[k][j] != INF)
                    {
                        if (dp[i][k] + dp[k][j] < dp[i][j])
                            dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (i != k && j != k & i != j)
                {
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        cout << "negative weight cycle exists";
                        return;
                    }
                }
            }
        }
    }
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, x, v, e, weight;
    int dp[100][100];

    cin >> v >> e;

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            dp[i][j] = 0;
    }

    for (x = 0; x < e; x++)
    {
        cin >> i >> j >> weight;
        dp[i][j] = weight;
    }

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (dp[i][j] == 0 && i != j)
                dp[i][j] = INF;
        }
    }

    Floyd_Warshall(v, dp);

    return 0;
}