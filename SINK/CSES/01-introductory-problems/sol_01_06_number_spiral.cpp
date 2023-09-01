#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll odd(ll x)
{
    if (x & 1)
    {
        return 1;
    }
    return 0;
}

ll even(ll x)
{
    if (x & 1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll row, col;
        cin >> row >> col;
        if (row >= col)
        {
            if (even(row))
                cout << row * row - col + 1 << '\n';
            else
                cout << (row - 1) * (row - 1) + col << '\n';
        }
        else
        {
            if (odd(col))
                cout << col * col - row + 1 << '\n';
            else
                cout << (col - 1) * (col - 1) + row << '\n';
        }
    }
    return 0;
}