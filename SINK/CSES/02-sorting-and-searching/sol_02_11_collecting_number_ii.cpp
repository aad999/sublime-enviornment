#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> plb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<plb> vplb;
#define for_up(i, m, n) for (ll i = m; i < n; i++)
#define for_upto(i, m, n) for (ll i = m; i <= n; i++)
#define for_down(i, m, n) for (ll i = m; i > n; i--)
#define for_downto(i, m, n) for (ll i = m; i >= n; i--)

int main()
{
    ll n, m;
    cin >> n >> m;
    vll index(n + 1);
    vll number(n + 1);
    for_up(i, 0, n)
    {
        ll a;
        cin >> a;
        index[a] = i + 1;
        number[i + 1] = a;
    }
    for_up(i, 0, m)
    {
        ll a, b;
        cin >> a >> b;
        swap(index[number[a]], index[number[b]]);
        swap(number[a], number[b]);
        ll ans = 1;
        for_upto(num, 2, n)
        {
            if (index[num] < index[num - 1])
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}