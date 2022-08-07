// Find how many binary search trees can be formed using n nodes with values 1,2,3,....,n

// Catalan number

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll factorial(int n)
{
    ll i, fact = 1;
    for (i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

ll ncr(ll n, ll r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

ll catalan(ll n)
{
    return ncr(2 * n, n) / (n + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    cout << catalan(n);
    return 0;
}