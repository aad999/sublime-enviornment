#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

bool sortcol(vll a, vll b)
{
    return a[0] < b[0];
}

int main()
{
    ll i, j;
    ll n, x;
    cin >> n >> x;
    vvll a(n, vll(2));
    for (i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end(), sortcol);
    i = 0, j = n - 1;
    ll p = -1, q = -1;
    while (i < j)
    {
        if (a[i][0] + a[j][0] == x)
        {
            p = a[i][1], q = a[j][1];
            break;
        }
        else if (a[i][0] + a[j][0] < x)
            i++;
        else
            j--;
    }
    if (p == -1 || q == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << p << ' ' << q << '\n';
    return 0;
}