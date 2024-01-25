#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll y, x;
        cin >> x >> y;
        if (x < y)
        {
            if (y % 2 == 1)
            {
                ll res = y * y;
                cout << res - x + 1 << endl;
            }
            else
            {
                ll res = (y - 1) * (y - 1) + 1;
                cout << res + x - 1 << endl;
            }
        }
        else
        {
            if (x % 2 == 0)
            {
                ll res = x * x;
                cout << res - y + 1 << endl;
            }
            else
            {
                ll res = (x - 1) * (x - 1) + 1;
                cout << res + y - 1 << endl;
            }
        }
    }
    return 0;
}