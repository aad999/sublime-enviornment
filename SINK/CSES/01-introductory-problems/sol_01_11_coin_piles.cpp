#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll a = (2 * x - y) / 3;
        ll b = (2 * y - x) / 3;
        bool yes = (a >= 0 && b >= 0 && x == 2 * a + b && y == 2 * b + a);
        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}