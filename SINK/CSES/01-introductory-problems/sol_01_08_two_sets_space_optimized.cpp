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

bool subset_of_sum(ll n, ll target)
{
    vnum dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= target; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[j])
            {
                continue;
            }
            if (i <= j)
            {
                if (dp[j - i])
                {
                    dp[j] = 1;
                    continue;
                }
            }
            dp[j] = 1;
            continue;
        }
    }
    return dp[target];
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
    if (subset_of_sum(n, sum / 2))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}