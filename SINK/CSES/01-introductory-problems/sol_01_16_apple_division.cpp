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
    return;
}

ll diff(ll a, ll b)
{
    return a > b ? a - b : b - a;
}

void evaluate(vector<ll> &v, ll &n, ll i, ll a, ll b, ll &min_diff)
{
    if (i >= n)
    {
        min_diff = min(min_diff, diff(a, b));
        return;
    }
    evaluate(v, n, i + 1, a + v[i], b, min_diff);
    evaluate(v, n, i + 1, a, b + v[i], min_diff);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    scanv(v, n);
    ll min_diff = INT_MAX;
    evaluate(v, n, 0, 0, 0, min_diff);
    cout << min_diff << '\n';
    return 0;
}