// Flood Fill Algorithm

#include <bits/stdc++.h>
using namespace std;

void floodFill(int i, int j, vector<vector<char>> &a, int n, int m)
{
    if (i < 0 | j < 0 || i >= n || j >= m)
        return;
    if (a[i][j] != '1')
        return;
    a[i][j] = '0';
    floodFill(i + 1, j, a, n, m);
    floodFill(i - 1, j, a, n, m);
    floodFill(i, j + 1, a, n, m);
    floodFill(i, j - 1, a, n, m);
}

int numIslands(vector<vector<char>> &a)
{
    int i, j, n = a.size(), m = a[0].size(), count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                count++;
                floodFill(i, j, a, n, m);
            }
        }
    }
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, m, n;
    char ch;
    vector<vector<char>> a;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        vector<char> temp;
        for (j = 0; j < m; j++)
        {
            cin >> ch;
            temp.push_back(ch);
        }
        a.push_back(temp);
    }
    cout<<numIslands(a);
    return 0;
}