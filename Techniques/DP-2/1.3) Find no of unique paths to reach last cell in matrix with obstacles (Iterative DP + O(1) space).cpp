// Instead of creating new matrix, store in given matrix itself
// Good approach if modification of given matrix is allowed
// Time: O(N*M)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size(), i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                a[i][j] = 0;
            else if (i == 0 && j == 0)
                a[i][j] = 1;
            else if (i == 0)
                a[i][j] = a[i][j - 1];
            else if (j == 0)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    return a[n - 1][m - 1];
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