#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> plb;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
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
    ll n;
    cin >> n;
    vll w(n);
    for_up(i, 0, n)
            cin >>
        w[i];
    multiset<ll> s;
    for_up(i, 0, n)
    {
        multiset<ll>::iterator it = s.lower_bound(w[i] + 1);
        if (it == s.end())
        {
            s.insert(w[i]);
        }
        else
        {
            s.erase(it);
            s.insert(w[i]);
        }
    }
    cout << s.size() << '\n';
    return 0;
}