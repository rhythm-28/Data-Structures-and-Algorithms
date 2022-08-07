// Two Pointer Algorithm

/*
To find which two elements in the
array differ to provide the given 
difference
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, n, diff, a[100];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cin >> diff;
    i = 0, j = i + 1;
    while (j < n)
    {
        if (i == j)
            j++;
        if (j == n)
            break;
        if ((a[j] - a[i]) == diff)
        {
            cout << a[i] << " " << a[j];
            break;
        }
        else if ((a[j] - a[i]) < diff)
            j++;
        else
            i++;
    }
    return 0;
}
