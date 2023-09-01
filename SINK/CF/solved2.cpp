#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<char> vchar;
typedef vector<vector<char>> vvchar;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

class Solution {
public:
	bool check_symmetry(vll& planks) {
		sort(planks.begin(), planks.end(), greater<int>());
		vpll stairs;
		map<ll, ll> freq;
		for (ll h : planks)
			freq[h]++;
		for (pll step : freq)
			stairs.push_back(step);
		reverse(stairs.begin(), stairs.end());
		// for(auto [h, f] : stairs)
		// 	cout << h << ' ' << f << '\n';
		// cout << '\n';
		ll h = planks.size(), x = 0, prev = -1, i = 0;
		for (pll step : freq) {
			pll new_pair = {h, step.first - x};
			if (stairs[i] != new_pair) {
				// cout << stairs[i].first << ' ' << stairs[i].second << " : " << new_pair.first << ' ' << new_pair.second << '\n';
				return false;
			}
			h -= step.second;
			x += (step.first - x);
			prev = step.first;
			i++;
		}
		return true;
	}
};

int main() {
	ll t;
	cin >> t;
	Solution sol;
	while (t--) {
		ll n;
		cin >> n;
		vll planks(n, 0);
		for (ll i = 0; i < n; i++)
			cin >> planks[i];
		if (sol.check_symmetry(planks))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}