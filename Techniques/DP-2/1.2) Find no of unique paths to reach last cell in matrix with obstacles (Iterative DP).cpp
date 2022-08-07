// Time: O(N*M)
// Space: O(N*M)

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size(), i, j;
    vector<vector<int>> dp(n, vector<int>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, n, m, y;
    vector<vector<int>> a;
    vector<int> temp;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> y;
            temp.push_back(y);
        }
        a.push_back(temp);
        temp.clear();
    }
    cout << uniquePathsWithObstacles(a);
    return 0;
}