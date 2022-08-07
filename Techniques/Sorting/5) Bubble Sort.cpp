// Bubble Sort
// in-place sorting
// repeatedly swaps adjacent elements if they are in wrong order
// finds largest element in unsorted array and paces it at beginning of sorted array
// TC : O(N^2)
// SC : O(1)

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)
    {
        for (j = 0; j <= n - 2 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

vector<int> sortArr(vector<int> a, int n)
{
    bubbleSort(a, n);
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