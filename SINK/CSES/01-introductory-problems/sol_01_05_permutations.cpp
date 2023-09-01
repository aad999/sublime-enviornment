#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    /*
        4
        2 4 1 3
        5
        2 4 1 3 5
        6
        2 4 6 1 3 5
        7
        2 4 6 1 3 5 7
        8
        2 4 6 8 1 3 5 7
        3
        2 1 3
        2
        2 1
        1
        1
    */
    if (n == 1 || n > 3)
    {
        for (int i = 2; i <= n; i = i + 2)
        {
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i = i + 2)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "NO SOLUTION\n";
    }
    return 0;
}