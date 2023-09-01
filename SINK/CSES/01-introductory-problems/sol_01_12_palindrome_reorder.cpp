#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool even(ll x)
{
    return !(x & 1);
}

bool odd(ll x)
{
    return x & 1;
}

int main()
{
    string str;
    cin >> str;
    ll len = str.size(); // length
    ll n = len;          // position
    ll rem = n;          // remaining
    vector<int> count(26, 0);
    for (char ch : str)
    {
        count[ch - 'A']++;
    }
    bool solved = true;
    for (int i = 0; i < 26 && n > len / 2; i++)
    {
        if (even(rem))
        {
            if (odd(count[i]))
            {
                solved = false;
                break;
            }
            else
            {
                while (count[i])
                {
                    if (n <= len / 2)
                    {
                        solved = false;
                        break;
                    }
                    str[n - 1] = 'A' + i;
                    str[len - n] = 'A' + i;
                    n--;
                    rem -= 2;
                    count[i] -= 2;
                }
                if (!solved)
                {
                    break;
                }
            }
        }
        else
        {
            if (odd(count[i]))
            {
                str[len / 2] = 'A' + i;
                rem--;
                count[i]--;
            }
            while (count[i])
            {
                if (n <= len / 2)
                {
                    solved = false;
                    break;
                }
                str[n - 1] = 'A' + i;
                str[len - n] = 'A' + i;
                n--;
                rem -= 2;
                count[i] -= 2;
            }
            if (!solved)
            {
                break;
            }
        }
    }
    if (solved)
    {
        cout << str << '\n';
    }
    else
    {
        cout << "NO SOLUTION\n";
    }
    return 0;
}