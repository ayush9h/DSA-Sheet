#include <iostream>
#include <vector>

using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll moves = 0;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << moves << endl;
    return 0;
}
