#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ll n;
    cin >> n;
    vll len(n);
    for (ll i = 0; i < n; i++)
        cin >> len[i];
    sort(len.begin(), len.end());
    ll mid = len[n / 2];
    ll cost = 0;
    for (ll i = 0; i < n; i++)
        cost += abs(mid - 0ll - len[i]);
    cout << cost << '\n';
    return 0;
}