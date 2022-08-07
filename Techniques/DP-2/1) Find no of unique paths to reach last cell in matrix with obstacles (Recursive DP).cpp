// Time: O(N*M)
// Space: O(N*M) (excluding recursion call stack space)

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &a, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i][j] == 1)
        return dp[i][j] = 0;
    if (i == n - 1 && j == m - 1)
        return 1;
    int down = helper(a, i + 1, j, n, m, dp);
    int right = helper(a, i, j + 1, n, m, dp);
    return dp[i][j] = down + right;
}

int uniquePathsWithObstacles(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(a, 0, 0, n, m, dp);
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