#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int count = 1;
    int ans = 1;
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        ans = max(ans, count);
    }
    cout << ans << '\n';
    return 0;
}