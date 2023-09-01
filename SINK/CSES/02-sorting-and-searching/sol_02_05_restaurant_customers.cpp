#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> dep(n);
    ll closing_time = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i] >> dep[i];
        closing_time = max(closing_time, max(arr[i], dep[i]));
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    ll a = 0, d = 0, _cs = 0, _maxcs = 0;
    while (a < n && d < n)
    {
        if (arr[a] == dep[d])
        {
            a++;
            d++;
        }
        else if (arr[a] < dep[d])
        {
            _cs++;
            _maxcs = max(_maxcs, _cs);
            a++;
        }
        else if (dep[d] < arr[a])
        {
            _cs--;
            _maxcs = max(_maxcs, _cs);
            d++;
        }
    }
    cout << _maxcs << '\n';
    return 0;
}