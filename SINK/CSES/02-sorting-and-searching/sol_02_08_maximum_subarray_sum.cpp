#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    bool all_negative = true;
    ll max_xi = INT_MIN;
    ll ans = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll xi;
        cin >> xi;
        max_xi = max(max_xi, xi);
        if (xi >= 0)
            all_negative = false;
        if (xi + sum >= 0)
            sum += xi;
        else if (xi >= 0)
            sum = xi;
        else
            sum = 0;
        ans = max(ans, sum);
    }
    if (all_negative)
        cout << max_xi << '\n';
    else
        cout << ans << '\n';
    return 0;
}