#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    ll _distinct = 0;
    ll i = 0;
    while (i < n)
    {
        _distinct++;
        ll j = i;
        while (j < n && x[j] == x[i])
            j++;
        i = j;
    }
    cout << _distinct << '\n';
    return 0;
}