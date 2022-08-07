// Insertion Sort
// picks an element from unsorted array and places it at its correct position in sorted array
// TC : O(N^2)
// SC : O(1)

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

vector<int> sortArr(vector<int> a, int n)
{
    insertionSort(a, n);
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