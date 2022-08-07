// Heap Sort
// in-place
// converts given aray into heap first, then places largest element at end and heapifies the remaining heap
// TC : O(NlogN)
// SC : O(1) (recursive space not inlcuded)

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int i, int size)
{
    int left = (2 * i) + 1, right = (2 * i) + 2, largest = i;
    if (left < size && a[left] > a[i])
        largest = left;
    if (right < size && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, largest, size);
    }
}

void convertToHeap(vector<int> &a, int n)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(a, i, n);
}

void heapSort(vector<int> &a, int n)
{
    convertToHeap(a, n);
    while (n > 1)
    {
        swap(a[0], a[n - 1]);
        n--;
        heapify(a, 0, n);
    }
}

vector<int> sortArr(vector<int> a, int n)
{
    heapSort(a, n);
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