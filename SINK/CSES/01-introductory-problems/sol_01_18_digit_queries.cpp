#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll _9 = 9;  //  9   90  900 9000
        ll _1 = 1;  //  1   2   3   4
        ll __1 = 1; //  1   10  100 1000
        while (n - (_9 * _1) > 0)
        {
            n -= (_9 * _1);
            _9 *= 10;
            _1++;
            __1 *= 10;
        }
        ll num = __1 + (n - 1) / _1;
        ll dig = _1 - 1 - (n - 1) % _1;
        while (dig--)
        {
            num /= 10;
        }
        ll res = num % 10;
        cout << res << '\n';
    }
    return 0;
}