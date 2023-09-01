#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<string> &gray)
{
    if (n == 1)
    {
        gray = {"0", "1"};
        return;
    }
    solve(n - 1, gray);
    ll size = gray.size();
    for (ll i = size - 1; i >= 0; i--)
    {
        gray.push_back(gray[i] + '1');
        gray[i].push_back('0');
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<string> gray;
    solve(n, gray);
    for (string s : gray)
    {
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}