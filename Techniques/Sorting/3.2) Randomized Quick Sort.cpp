// Randomized Quick Sort
// Average : O(NlogN)
// Worst : O(N^2)

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int h)
{
    srand(time(NULL));
    int k = l + rand() % (h - l);
    swap(a[k], a[h]);
    int i = l, j, pivot = a[h];
    for (j = l; j <= h - 1; j++)
    {
        if (a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[h]);
    return i;
}

void quickSort(vector<int> &a, int l, int h)
{
    if (l >= h)
        return;
    int p = partition(a, l, h);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, h);
}

vector<int> sortArr(vector<int> a, int n)
{
    quickSort(a, 0, n - 1);
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