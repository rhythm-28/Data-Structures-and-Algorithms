// Flood Fill Algorithm

#include <bits/stdc++.h>
using namespace std;

void floodFill(int i, int j, vector<vector<int>> &a, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (a[i][j] != 1)
        return;
    a[i][j] = 0;
    floodFill(i + 1, j, a, n, m);
    floodFill(i - 1, j, a, n, m);
    floodFill(i, j - 1, a, n, m);
    floodFill(i, j + 1, a, n, m);
}

int numEnclaves(vector<vector<int>> &a)
{
    int i, j, n = a.size(), m = a[0].size(), count = 0;
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i][j] == 1)
            floodFill(i, j, a, n, m);
    }
    j = m - 1;
    for (i = 0; i < n; i++)
    {
        if (a[i][j] == 1)
            floodFill(i, j, a, n, m);
    }
    i = 0;
    for (j = 0; j < m; j++)
    {
        if (a[i][j] == 1)
            floodFill(i, j, a, n, m);
    }
    i = n - 1;
    for (j = 0; j < m; j++)
    {
        if (a[i][j] == 1)
            floodFill(i, j, a, n, m);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                count++;
        }
    }
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, m, n,x;
    vector<vector<int>> a;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        vector<int> temp;
        for (j = 0; j < m; j++)
        {
            cin >> x;
            temp.push_back(x);
        }
        a.push_back(temp);
    }
    cout << numEnclaves(a);
    return 0;
}