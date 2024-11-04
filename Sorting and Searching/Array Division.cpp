#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<ll> v;

bool check(ll k, ll val)
{
    ll x = 0, run = 0;
    for(int i = 0; i < v.size(); i++)
    {
        run += v[i];
        if(run > val) 
        {
            x++;
            i--;
            run = 0;
        }
        if(x > k) return 0;
    }
    if(x + 1 > k) return 0;
    return 1;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll l = 1, h = 1e15, m = 1, ans;
    while(l <= h)
    {
        m = (l + h) / 2ll;
        if(check(k, m)) ans = m, h = m - 1;
        else l = m + 1;
    }
    cout << ans;
}