#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int8_t num;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<int8_t> vnum;
typedef vector<vector<int8_t>> vvnum;

bool odd(ll x)
{
    return x & 1;
}

bool subset_of_sum(ll n, vnum &status, vvnum &dp, ll target)
{
    if (target == 0)
    {
        return true;
    }
    if (n <= 0)
    {
        return false;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    // not including n
    if (subset_of_sum(n - 1, status, dp, target))
    {
        dp[n][target] = 1;
        return true;
    }
    if (n <= target)
    {
        // including n
        status[n] = 1;
        if (subset_of_sum(n - 1, status, dp, target - n))
        {
            dp[n][target] = 1;
            return true;
        }
    }
    // answer doesn't exist
    status[n] = -1;
    dp[n][target] = 0;
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
    vnum status(n + 1, -1);
    vvnum dp(n + 1, vnum(sum / 2 + 1, -1));
    if (subset_of_sum(n, status, dp, sum / 2))
    {
        cout << "YES\n";
        vll inc;
        vll not_inc;
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