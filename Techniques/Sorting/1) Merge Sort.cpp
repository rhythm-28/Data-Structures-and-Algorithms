// Merge Sort
// divides array into two halves, recursively call for both halves and then merge the two resulting parts
// TC : O(NlogN)
// SC : O(N)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &c, int l, int mid, int h)
{
    vector<int> a, b;
    int i, j, k, n, m;
    for (i = l; i <= mid; i++)
        a.push_back(c[i]);
    for (i = mid + 1; i <= h; i++)
        b.push_back(c[i]);
    n = a.size(), m = b.size(), i = 0, j = 0, k = l;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];
}

void mergeSort(vector<int> &a, int l, int h)
{
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, h);
    merge(a, l, mid, h);
}

vector<int> sortArr(vector<int> a, int n)
{
    mergeSort(a, 0, n - 1);
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