// to find factorial of a big number
// works perfectly well upto n = 10 ^ 6
// after that it slows down

#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define MOD 1000000007
lli factorial(lli n)
{
    lli i, fact = 1;
    for (i = 2; i <= n; i++)
        fact = (fact * i) % MOD;
    return fact;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    lli n;

    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}
