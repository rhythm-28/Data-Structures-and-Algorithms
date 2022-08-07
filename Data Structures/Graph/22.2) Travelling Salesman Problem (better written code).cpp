#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &a, int n, vector<vector<int>> &dp, int visited, int cur, int done)
{
    if (visited == done)
        return a[cur][0];

    if (dp[visited][cur] != -1)
        return dp[visited][cur];
    int nbr, x, y, ans = INT_MAX;

    for (nbr = 0; nbr < n; nbr++)
    {
        x = 1 << nbr;

        // not visited
        if ((visited & x) == 0)
        {
            y = a[cur][nbr] + helper(a, n, dp, visited | x, nbr, done);
            ans = min(ans, y);
        }
    }
    return dp[visited][cur] = ans;
}

int total_cost(vector<vector<int>> &a)
{
    int n = a.size(), done = pow(2, n) - 1;
    vector<vector<int>> dp(done, vector<int>(n, -1));
    return helper(a, n, dp, 1, 0, done);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        int ans = total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
}