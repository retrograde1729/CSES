#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

bool c(vector<ll>& t, ll k, ll m)
{
    for(ll i : t) {k -= m / i; if(k <= 0) return 1;}
    return (k <= 0) ? 1 : 0;
}

int main()
{
    ll n, k, ans;
    cin >> n >> k;
    vector<ll> t(n, 0);
    for(int i = 0; i < n; i++) cin >> t[i];
    ll l = 0, h = 1e18, m = 1;
    while(l <= h)
    {
        m = (l + h) / 2LL;
        if(c(t, k, m)) ans = m, h = m - 1;
        else l = m + 1;
    } 
    
    cout << ans;
}