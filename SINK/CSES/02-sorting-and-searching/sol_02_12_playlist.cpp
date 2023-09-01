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
    vll song(n);
    for_up(i, 0, n)
            cin >>
        song[i];
    mlb heared;
    mll last_heared;
    ll capacity = 1;
    ll begin = 0;
    heared[song[begin]] = true;
    last_heared[song[begin]] = 0;
    ll end = 1;
    while (end < n)
    {
        // cout << begin << ' ' << end << " -> ";
        if (heared[song[end]] && last_heared[song[end]] >= begin)
            begin = last_heared[song[end]] + 1;
        heared[song[end]] = true;
        last_heared[song[end]] = end;
        ll _songs = end - begin + 1;
        capacity = max(capacity, _songs);
        end++;
        // cout << begin << ' ' << end << '\n';
    }
    cout << capacity << '\n';
    return 0;
}