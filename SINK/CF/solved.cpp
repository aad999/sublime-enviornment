#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<char> vchar;
typedef vector<vector<char>> vvchar;

class Solution {
	vvchar carpet;
	string target = "vika";
	map<char, map<int, bool>> present;
	vvll dp;
	bool rec(ll col, ll i) {
		if (i >= target.size())
			return true;
		if (col >= carpet[0].size())
			return false;
		if (dp[col][i] != -1)
			return dp[col][i];
		if (present[target[i]][col])
			return dp[col][i] = rec(col + 1, i + 1);
		return dp[col][i] = rec(col + 1, i);
	}
public:
	bool check(vvchar& carpet) {
		this->carpet = carpet;
		for (ll col = 0; col < carpet[0].size(); col++)
			for (ll row = 0; row < carpet.size(); row++)
				present[carpet[row][col]][col] = true;
		dp.resize(carpet[0].size() + 1, vll(target.size() + 1, -1));
		return rec(0, 0);
	}
};

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll rows, cols;
		cin >> rows >> cols;
		vvchar carpet(rows, vchar(cols, ' '));
		for (ll i = 0; i < rows; i++)
			for (ll j = 0; j < cols; j++)
				cin >> carpet[i][j];
		Solution sol;
		if (sol.check(carpet))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}