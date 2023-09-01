#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int testCase = 1;
    while (testCase--)
    {
        ll _t, _p;
        cin >> _t >> _p;
        multiset<ll> ticket_prices;
        for (ll i = 0; i < _t; i++)
        {
            ll price;
            cin >> price;
            ticket_prices.insert(price);
        }
        for (ll i = 0; i < _p; i++)
        {
            ll payment;
            cin >> payment;
            auto ticket_id = ticket_prices.upper_bound(payment);
            if (ticket_id == ticket_prices.begin())
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                cout << *(--ticket_id) << endl;
                ticket_prices.erase(ticket_id);
            }
        }
    }
    return 0;
}