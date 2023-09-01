#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool odd(ll x)
{
    return x & 1;
}

bool subset_of_sum(ll n, vector<int8_t> &status, ll target)
{
    if (target == 0)
    {
        if (n > 0)
        {
            status[n] = -1;
        }
        return true;
    }
    if (n <= 0)
    {
        return false;
    }
    // not including n
    status[n] = -1;
    if (subset_of_sum(n - 1, status, target))
    {
        return true;
    }
    // including n
    status[n] = 1;
    if (subset_of_sum(n - 1, status, target - n))
    {
        return true;
    }
    // answer doesn't exist
    status[n] = 0;
    return false;
}

int main()
{
    ll n;
    cin >> n;
    ll sum = (n * 1ll * (n + 1)) / 2;
    if (odd(sum))
    {
        cout << "NO\n";
        return 0;
    }
    vector<int8_t> status(n + 1, 0);
    if (subset_of_sum(n, status, sum / 2))
    {
        cout << "YES\n";
        vector<ll> inc;
        vector<ll> not_inc;
        for (ll i = 1; i <= n; i++)
        {
            if (status[i] > 0)
                inc.push_back(i);
            if (status[i] < 0)
                not_inc.push_back(i);
        }
        cout << inc.size() << '\n';
        for (ll inci : inc)
        {
            cout << inci << ' ';
        }
        cout << '\n';
        cout << not_inc.size() << '\n';
        for (ll not_inci : not_inc)
        {
            cout << not_inci << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}