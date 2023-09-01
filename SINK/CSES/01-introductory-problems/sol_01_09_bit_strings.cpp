#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;

int main()
{
    /*
        (a *+- b) mod m
            = (a mod m *+- b mod m) mod m
    */
    ll n;
    cin >> n;
    ll x = 1;
    for (ll i = 0; i < n; i++)
    {
        x = x << 1;
        x = x % m;
    }
    cout << x << '\n';
    return 0;
}