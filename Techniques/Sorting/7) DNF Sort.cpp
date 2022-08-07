// DNF Sort
// TC : O(N)
// SC : O(1) 

#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a, int n)
{
    int l = 0, mid = 0, h = n - 1;
    while (mid <= h)
    {
        if (a[mid] == 0)
        {
            swap(a[l], a[mid]);
            l++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[h]);
            h--;
        }
    }
}
vector<int> sortArr(vector<int> a, int n)
{
    sort012(a, n);
    return a;
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
    a = sortArr(a, n);
    for (auto x : a)
        cout << x << " ";
    return 0;
}