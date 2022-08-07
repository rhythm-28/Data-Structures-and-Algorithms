// Find no of pairs of positions in array such that their sum is equal to given value

#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli getPairsCount(lli arr[], lli n, lli sum)
{
    unordered_map<lli, lli> m;

    // frequency of each element
    for (lli i = 0; i < n; i++)
        m[arr[i]]++;

    lli count = 0, remaining_sum;

    for (lli i = 0; i < n; i++)
    {
        // remaining sum after choosing one element
        remaining_sum = sum - arr[i];

        // no of elements that give the given sum with a[i]
        count += m[remaining_sum];

        // removing pair (a[i],a[i])
        if (remaining_sum == arr[i])
            count--;
    }

    // as each pair is counted twice
    return count / 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    lli t, i, n, a[200005], sum, x;
    cin >> sum;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << getPairsCount(a, n, sum);
    return 0;
}
