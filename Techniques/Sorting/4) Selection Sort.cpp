// Selection Sort
// divides array in two parts- unsorted and sorted.
// finds smallest element from unsorted part and places it at end of sorted part
// TC : O(N^2)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

vector<int> sortArr(vector<int> a, int n)
{
    selectionSort(a, n);
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