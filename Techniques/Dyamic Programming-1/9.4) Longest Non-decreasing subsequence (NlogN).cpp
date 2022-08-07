// Longest Non-decreasing subsequence
// using Binary Search
// very similar to LIS 
// TC: O(NlogN)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &a)
{
    int i, n = a.size();
    vector<int> lis;
    lis.push_back(a[0]);
    for (i = 1; i < n; i++)
    {
        if (a[i] >= lis.back())
            lis.push_back(a[i]);
        else
        {
            int j = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[j] = a[i];
        }
    }
    return lis.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, temp;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    cout << lengthOfLIS(a);
    return 0;
}