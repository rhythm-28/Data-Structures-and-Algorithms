// Sort a vector using Merge Sort 

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &c, int low, int mid, int high)
{
    vector<int> a, b;
    int i, j, k, n, m;
    for (i = low; i <= mid; i++)
        a.push_back(c[i]);
    for (i = mid + 1; i <= high; i++)
        b.push_back(c[i]);
    n = a.size(), m = b.size(), k = low, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &a, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, i, temp;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    mergeSort(a, 0, n - 1);
    for (auto &x : a)
        cout << x << " ";
    return 0;
}