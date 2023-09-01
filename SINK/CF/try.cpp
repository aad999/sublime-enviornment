#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findN(ll x) {

    ll low = 0, high = 2700000000, n = 0;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if((mid * (mid + 1)) <= (2 * x))
            n = (low = mid + 1);
        else
            high = mid - 1;
    }
    return n;

}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll n = findN(x);
        cout << "The value of n for " << x << " is: " << n << '\n';
    }
    return 0;
}
