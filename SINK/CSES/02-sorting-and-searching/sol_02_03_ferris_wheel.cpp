#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll _gondolas = 0;
    ll i = 0;
    ll n, x;
    cin >> n >> x;
    vector<ll> wt(n);
    for (i = 0; i < n; i++)
        cin >> wt[i];
    sort(wt.begin(), wt.end());
    // for(auto wti : wt)
    //     cout << wti << ' ';
    // cout << '\n';
    i = 0;
    ll j = n - 1;
    while (i <= j)
    {
        while (i < j && wt[i] + wt[j] > x)
        {
            j--;
            _gondolas++;
        }
        j--;
        i++;
        _gondolas++;
    }
    cout << _gondolas << '\n';
    return 0;
}