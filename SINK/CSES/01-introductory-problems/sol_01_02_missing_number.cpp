#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void scanv(vector<ll> &v, ll size)
{
    for (ll i = 0; i < size; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
}

ll is_even(ll x)
{
    if (x & 1)
        return 0;
    return 1;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    scanv(v, n - 1);
    ll actual = 0;
    for (ll vi : v)
    {
        actual += vi;
    }
    ll expected = (n / (1 + is_even(n))) * 1ll * ((n + 1) / (1 + is_even(n + 1)));
    cout << expected - actual << '\n';
    return 0;
}
