#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{   
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--) {
        ll n,c = 0,sum=0;
        cin>>n;
        map < ll, ll > ma;
        for(ll i = 2 ; i*i <= n ; i++) {
            c=0;
            while(n%i == 0) {
                c++;
                n/=i;
                if(!ma.count(c)) {
                    ma[c] = i;
                }
                else {
                    ma[c]*=i;
                }
            }
        }
        if(n != 1) {
            if(!ma.count(1))
                ma[1] = n;
            else {
                ma[1]*=n;
            }
        }
        map < ll , ll >::iterator it;
        for(it = ma.begin(); it!=ma.end() ; it++) {
            sum+=it->second;
        }
        cout<<sum<<endl;
    }

    return 0;     
 }
