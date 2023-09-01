#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll i;
    cin >> i;
    cout << i << " ";
    while (i != 1)
    {
        if (i & 1)
        {
            i *= 3;
            i++;
        }
        else
        {
            i /= 2;
        }
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
