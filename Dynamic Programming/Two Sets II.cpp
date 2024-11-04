#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;  
const int inf = 1e8;

ll power(ll a, ll b) 
{
    ll result = 1;
    a = a % mod;
    while (b > 0) 
    {
        if (b & 1) 
        {
            result = (result * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return result;
}

ll solve(ll n)
{
    if((n * (n + 1)) % 4) return 0;

    ll sum = n * (n + 1) / 4;
    vector<ll> dp(sum + 1, 0);
    dp[0] = 1;

    for(ll i = n; i > 0; i--)
    {
        for(ll j = sum; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    
    return (dp[sum] * power(2, mod - 2)) % mod;
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n) << '\n';
}