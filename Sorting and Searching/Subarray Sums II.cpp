#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, x;
    cin >> n >> x;
    ll a = 0, b = 0, ans = 0;
    unordered_map<ll, ll> ump;
    ump.reserve(1 << 22);
    ump[0] = 1;
    for(int i = 0; i < n; i++) 
    {
        cin >> b;
        b += a;
        ans += ump[b - x];
        a = b;
        ump[a]++;
    }
    cout << ans;
}