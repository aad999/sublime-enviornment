#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll number_of_twos = 0;
    ll power_of_two = 2;
    while (power_of_two <= n)
    {
        number_of_twos += (n / power_of_two);
        power_of_two *= 2;
    }
    ll number_of_fives = 0;
    ll power_of_five = 5;
    while (power_of_five <= n)
    {
        number_of_fives += (n / power_of_five);
        power_of_five *= 5;
    }
    ll ans = min(number_of_twos, number_of_fives);
    cout << ans << '\n';
    return 0;
}