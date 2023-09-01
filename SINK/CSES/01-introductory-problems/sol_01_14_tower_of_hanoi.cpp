#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;

int transfer(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    int x = transfer(n - 1, a, c, b);
    moves.push_back({a, c});
    int y = transfer(n - 1, b, a, c);
    return x + y + 1;
}

int main()
{
    int n;
    cin >> n;
    int _moves = transfer(n, 1, 2, 3);
    cout << _moves << '\n';
    for (auto move : moves)
    {
        cout << move.first << " " << move.second << '\n';
    }
    return 0;
}