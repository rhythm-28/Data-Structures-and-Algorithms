// Boyer Moore Majority Voting Algorithm
// Find the element that occurs more than n/2 times
// if no such element is there, print -1
// Time: O(N)
// Space: O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int n)
{
    int i, ans = a[0], count = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] == ans)
            count++;
        else
            count--;
        if (count == 0)
        {
            ans = a[i];
            count = 1;
        }
    }
    count = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ans)
            count++;
    }
    if (count > n / 2)
        return ans;
    else
        return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, temp, i;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    cout << solve(a, n);
    return 0;
}