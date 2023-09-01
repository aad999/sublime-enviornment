#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sqr(ll x)
{
    return x * 1ll * x;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        /*
            all cases :
                (i^2)C2 = (i^2) * ((i^2)-1) / 2
            invalid cases :
                2 * number of 3*2 or 2*3 boxes in the i*i boxes
                    = 2 * 2 * (i-2) * (i-1)
                        = 4 * (i-2) * (i-1)
            valid cases :
                all cases - invalid cases
        */
        ll all_cases = (sqr(i) * 1ll * (sqr(i) - 1)) / 2;
        ll invalid_cases = 4 * 1ll * (i - 2) * 1ll * (i - 1);
        ll valid_cases = all_cases - invalid_cases;
        cout << valid_cases << '\n';
    }
    return 0;
}