#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;

    vector<ll> arr(n - 1);

    for (ll i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
        sum -= arr[i];
    }

    cout << sum << " ";

    return 0;
}
