#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void scanv(vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    scanv(v, n);
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = v[i - 1] - v[i];
        if (diff > 0)
        {
            ans += diff;
            v[i] = v[i - 1];
        }
    }
    cout << ans << '\n';
    return 0;
}